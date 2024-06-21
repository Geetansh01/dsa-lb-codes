/*
    This problem can be solved by 3 methods:
    1.Hashing
    2.Sum Formula
    3.Bit manupulation i.e using XOR.
    
    1)HASHING : In this Method, We can iterate over all the element upto the n and compare it with the present element by creating the hash map of (n+1).
        Time Complexity = O(n)
        Space complexity =O(n)

        Issue :- Though it is taking the space complexity of N, So we move on to the next Method.
    
    2)Sum Formula : In this we us e the sum formula i.e : Sn = N(N+1)/2 & Sum of all the array(Sa[]).
    And after this we subtract the (Sn-Sa[]) to find the Missing Number.
        Time Complexity = O(n)
        Space complexity =O(1)

        Issue :- It can cause the Overflow issue because in this we are adding the element, So if the array element is very large then it can cause Integer Overflow.
        To handle out this Overflow we can use the Next Method which is XOR Bit Manipulation.

    3)XOR Bit Manipulation : In this we take the XOR of given array and the first n natural number.
        Time Complexity = O(n)
        Space complexity =O(1)
        No Overflow.
*/