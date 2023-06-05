
#include <iostream>
#include <cstring>
#include <map>
#include<vector>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;

        map<char, int> gquiz1;
        // insert elements in random order
        gquiz1.insert(pair<char, int>('I', 1));
        gquiz1.insert(pair<char, int>('V', 5));
        gquiz1.insert(pair<char, int>('X', 10));
        gquiz1.insert(pair<char, int>('L', 50));
        gquiz1.insert(pair<char, int>('C', 100));
        gquiz1.insert(pair<char, int>('D', 500));
        gquiz1.insert(pair<char, int>('M', 1000));
        int lent = s.length();
        for (int i = 0;i < lent;i++) {

            switch (s[i])
            {
            case 'I':
                if (i + 1 < lent && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    sum += gquiz1[s[i + 1]] - gquiz1[s[i]];
                    i++;
                }
                else
                {
                    sum += gquiz1[s[i]];
                }
                break;
            case 'X':
                if (i + 1 < lent && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    sum += gquiz1[s[i + 1]] - gquiz1[s[i]];
                    i++;
                }
                else
                {
                    sum += gquiz1[s[i]];
                }
                break;
            case 'C':
                if (i + 1 < lent && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    sum += gquiz1[s[i + 1]] - gquiz1[s[i]];
                    i++;
                }
                else
                {
                    sum += gquiz1[s[i]];
                }
                break;
            default:
                sum += gquiz1[s[i]];
                break;
            }
        }
         return sum;
    }
};

class Solution724 {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int leftSum = 0;
        int rightsum = 0;
        
        for (int i = 0;i < size;i++) {  
            rightsum += nums[i];
        }

       
        for (int i = 0; i < size; i++)
        {
            rightsum -= nums[i];
            if (rightsum == leftSum) {
                return i;
            }         
            leftSum += nums[i];
        }

        return -1;
    }
};

class Solution1480 {
    public:
        vector<int> runningSum(vector<int>& nums) {
            vector<int> sums;
            int size = nums.size();
            int sum= 0;
            for (int i = 0;i < nums.size();i++) {
                sum += nums[i];
                sums.push_back(sum);
            }
            return sums;
        } 
};

class Solution205 {
  public :
      bool isIsomorphic(string s, string t) {
          map<char, char> cahrList;
          map<char, char> cahrList2;
          int lent = s.size();
          for (int i = 0;i <lent;i++) {               
              
              if (cahrList.find(s[i]) != cahrList.end()) {
                  if (t[i] != cahrList[s[i]]) {
                      return false;
                  }
              }
              else {
                  cahrList.insert(pair<char, int>(s[i], t[i]));              
              }

              if (cahrList2.find(t[i]) != cahrList2.end()) {
                  if (s[i] != cahrList2[t[i]]) {
                      return false;
                  }
              }
              else
              {
                  cahrList2.insert(pair<char, int>(t[i], s[i]));
              }
          
          }
          return true;
      }

};

class Solution392 {
 public : 
     bool isSubsequence(string s, string t) {
         int index = 0;
         //int founded = 0;
        
             for (int i = 0;i < t.length();i++) {
                 if (s[index] == t[i]) {                    
                     if (++index == s.length()) return true;
                 }
             }
         
     
         return false;
     }
};


//  Definition for singly-linked list.
  struct ListNode {
      
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

  };
 
  class Solution45565646 {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  

          ListNode* newList;

          if (list1 == NULL)
          {
              return list2;
          }
          else if (list2 == NULL)
          {
              return list1;
          }
          else
          {
              if (list1->val > list2->val) {
                  newList = list2;    
                  list2 = list2->next;
              }
              else {
                  newList = list1;
                  list1 = list1->next;
              }
          }
        
          ListNode* newListHead = newList;




          while (list1&&list2)
          {

              if (list1->val < list2->val) {
          
                  
                  newList->next = list1;
                 
                  list1 = list1->next;
              }
              else {
              
                  newList->next = list2;
                  list2 = list2->next;
              }
              newList = newList->next;
          }


          if (list1) {
              newList->next = list1;
          }
          else if(list2)
          {
              newList->next = list2;
          }
         

          return newListHead;
         
      }
  };

 /* class Solution2 {

  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          long num1 = 0;
          long cIndex = 1;
         
          //2 4 9

          int flow = 0;

          ListNode* sumList = new ListNode();
          ListNode* index = sumList;

          while (l1&&l2)
          {
              index = new ListNode();

              int sum = l1->val+l2->val;
              int digit =sum%10;
              index->val = digit +flow;
              //index->next = new ListNode(digit, nullptr);              
              index = index->next;
              flow =sum/10;
          }

          while (l1)
          {
              int digit = l1->val;
              index->val = digit;
              index->next = new ListNode(digit, nullptr);
              index = index->next;
              flow = sum / 10;
          }

          return sumList;

      }
  };*/

class Solution19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* _point = head;
        ListNode* _last = head;
        ListNode* p = head;
        
        while (--n)
        {
          _last = _last->next;           
        }

        while (_last->next) {
            _last = _last->next;
            p = _point;
            _point = _point->next;
        }


        if (_point == head) {           
            return _point->next;
        }
        p->next = p->next->next;

        return head;

    }
};
/*
void test1() {
    ListNode* node1 = new ListNode(2, new ListNode(4, new ListNode(9, NULL)));
    ListNode* node2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9, NULL))));
    Solution2 s;
    ListNode* node = s.addTwoNumbers(node1, node2);
    while (node)
    {
        cout << "last " << node->val << endl;
        node = node->next;
    }
}*/



/*void test2() {
    ListNode* node1 = new ListNode(0,NULL);
    ListNode* node2 = new ListNode(0,NULL);
    Solution2 s;
    ListNode* node = s.addTwoNumbers(node1, node2);
    while (node)
    {
        cout << "last " << node->val << endl;
        node = node->next;
    }
}*/

/*void test3() {
    ListNode* node1 = 
        new ListNode(9, 
            new ListNode(9, 
                new ListNode(9,
                    new ListNode(9,
                        new ListNode(9,
                             new ListNode(9,
                              NULL))))));
    ListNode* node2 = 
        new ListNode(9,
            new ListNode(9, 
                new ListNode(9,
                  new ListNode(9,
                     NULL))));
    Solution2 s;
    ListNode* node = s.addTwoNumbers(node1, node2);
    while (node)
    {
        cout << "last " << node->val << endl;
        node = node->next;
    }
}*/


#include"Problem1759.h"
int main()
{
   
    Problem1759 problem1759;
    problem1759.StartTest();
    

    return 0;

    

}



