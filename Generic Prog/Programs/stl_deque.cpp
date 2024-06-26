    #include <iostream>
    #include <deque>

    using namespace std;

    int main()
    {
        deque<int> dq;

        dq.push_back(1);   // added element at the back
        dq.push_front(2);  // added element at the front
        dq.push_back(3);   // added element at the back
        dq.push_front(4);  // added element at the front


        deque<int>::iterator it;

        cout << "The deque dq is: ";
        for (it = dq.begin(); it != dq.end(); it++)
        {	
            cout << *it << " ";
        }

        cout << "\ndq.size(): " << dq.size();

        // removing first element of deque
        dq.pop_front();

        cout << "\nDeque after using pop_front() is: ";
        for (it = dq.begin(); it != dq.end(); it++)
        {	
            cout << *it << " ";
        }
        //funtion for pop_back
        dq.pop_back();
        dq.pop_back();

        return 0;
    }
