
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long int64;

int main()
{
    int number_of_cases;
    cin >> number_of_cases;
    for (int c = 0; c < number_of_cases; c++)
    {
        int number_of_books;
        int number_of_scribers;
        cin >> number_of_books;
        cin >> number_of_scribers;
        vector<int64> number_of_pages;
        for (int b = 0; b < number_of_books; b++)
        {
            int64 number_of_page;
            cin >> number_of_page;
            number_of_pages.push_back(number_of_page);
        }

        vector<int64> running_sums;
        running_sums.push_back(0);
        int64 sum = 0;
        for (int b = 0; b < number_of_books; b++)
        {
            sum += number_of_pages[b];
            running_sums.push_back(sum);
        }

        int64** optimal = new int64*[number_of_books];
        for (int b = 0; b < number_of_books; b++)
        {
            optimal[b] = new int64[number_of_scribers];
        }

        for (int b = 0; b < number_of_books; b++)
        {
         
            optimal[b][0] = running_sums[number_of_books] - running_sums[number_of_books - 1 - b];
        }

        for (int q = 1; q < number_of_scribers; q++)
        {
            for (int p = 0; p < number_of_books; p++)
            {
                int64 currest_best_split_cost = running_sums[number_of_books] + 1;

                //should be able to reduce this cost by using binary search
                for (int i = number_of_books - p - 1; i < number_of_books - q; i++)
                {
                    int64 cost_to_split_at_i = max(running_sums[i + 1] - running_sums[number_of_books - p - 1], optimal[number_of_books - i - 2][q - 1]);
                    currest_best_split_cost = min(currest_best_split_cost, cost_to_split_at_i);
                }
                optimal[p][q] = currest_best_split_cost;
            }
        }

        int64 solution = optimal[number_of_books - 1][number_of_scribers - 1];

        stack<int> split_index;
        int64 current_sum = 0;
        int remaining_scriber_count = number_of_scribers - 1;
        for (int b = number_of_books - 1; b >= 0; b--)
        {
            if (current_sum + number_of_pages[b] <= solution && b >= remaining_scriber_count)
            {
                current_sum += number_of_pages[b];
            }
            else
            {
                remaining_scriber_count--;
                current_sum = 0;
                b++;
                split_index.push(b);
            }
        }


        int current_split_index = split_index.top();
        split_index.pop();
        for (int b = 0; b < number_of_books; b++)
        {
            if (b == current_split_index)
            {
                cout << "/ ";
                cout << number_of_pages[b];
                if (split_index.size() > 0)
                {
                    current_split_index = split_index.top();
                    split_index.pop();
                }
                else {
                    current_split_index = -1;
                }
            }
            else
            {
                cout << number_of_pages[b];
            }
            if (b != number_of_books - 1)
            {
                cout << " ";
            }
        }
        cout << endl;


        for (int b = 0; b < number_of_books; b++)
        {
            delete[] optimal[b];
        }
        delete[] optimal;

    }
    return 0;
}
