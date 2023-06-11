// AddTwoNumbers_Sol2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void checkResult(ListNode*& result, int &carry)
{
    if (result->val > 9)
    {
        //highest digit is 9 so the sum of two values can never be greater than 18
        //subtract from 10
        result->val = result->val - 10;
        carry = 1;
    }
    else
    {
        cout << "Carry: " << carry << endl;
        //reset carry
        carry = 0;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* result = new ListNode;
        ListNode* resultHead = result;
        int carry = 0;
        //l1 + l2
        ListNode* current1 = l1;
        ListNode* current2 = l2;

        while ((current1 != NULL) || (current2 != NULL) || (carry != 0))
        {
            //check if one of the values is NULL
            if (current1 == NULL)
            {
                if (current2 == NULL)
                {
                    if(carry == 0)
                        return resultHead;
                    else
                    {
                        result->val = carry;
                        return resultHead;
                    }
                }
                else
                {
                    //add 0 for NULL value
                    result->val = 0 + current2->val + carry;
                    checkResult(result, carry);

                    cout << "Sum: " << result->val << endl;

                    //move to next elements
                    //current1 is NULL so no need to move
                    current2 = current2->next;
                    if (current2 || carry)
                    {
                        result->next = new ListNode;
                        result = result->next;
                    }
                }
            }
            else if (current2 == NULL)
            {
                //add 0 for NULL value
                result->val = current1->val + 0 + carry;
                checkResult(result, carry);

                cout << "Sum: " << result->val << endl;

                //move to next elements
                //current2 is NULL so no need to move
                current1 = current1->next;
                if (current1 || carry)
                {
                    result->next = new ListNode;
                    result = result->next;
                }
            }
            else
            {
                //no values are NULL
                result->val = current1->val + current2->val + carry;
                checkResult(result, carry);

                cout << "Sum: " << result->val << endl;

                //move to next list element
                current1 = current1->next;
                current2 = current2->next; 
                if (current1 || current2 || carry)
                {
                    result->next = new ListNode;
                    result = result->next;
                }
            }
        }
        return resultHead;
    }
};

int main()
{
    //list 1
    ListNode l7(9);
    ListNode l6(9, &l7);
    ListNode l5(9, &l6);
    ListNode l4(9, &l5);
    ListNode l3(9, &l4);//3rd node pointing to next node
    ListNode l2(9, &l3); //2nd node pointing to 3rd
    ListNode l1(9, &l2); //1st node pointing to 2nd

    //list 2
    ListNode m4(9);
    ListNode m3(9, &m4); //3rd node pointing to next node
    ListNode m2(9, &m3); //2nd node pointing to 3rd
    ListNode m1(9, &m2); //1st node pointing to 2nd

    Solution obj1;
    ListNode* result = obj1.addTwoNumbers(&l1, &m1);

    ListNode* currentNode = result;
    while (currentNode != NULL)
    {
        cout << currentNode->val << endl;
        currentNode = currentNode->next;
    }
}