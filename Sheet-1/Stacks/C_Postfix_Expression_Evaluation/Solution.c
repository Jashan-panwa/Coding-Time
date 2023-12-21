Implement a program to evaluate a postfix expression.

Input Format

The first input will be a single integer N denoting the number of test cases to take. After this there will be exactly N lines, each line a valid postfix string. The string will be a valid postfix expression consisting of only integers and binary operators (+, -, *, / and ?).

Every integer and operator will be compulsorily separated by a SPACE. The symbol ‘?’ denotes the end of expression.

Constraints

NA

Output Format

Exactly N lines, each line denoting the output of the expression. In case the output is in fractions, please print only the integer part of the output.

Sample Input 0

1
31 4 50 + * ? 
Sample Output 0

1674
Sample Input 1

5
12 23 + 14 - ?
2 43 12 * + 12 + ? 
12 3 + 12 3 + * 12 3 + / ? 
32 34 12 * + 1 2 + * 1 1 + / 23 21 - * ?
12 10 * 12 / ?
Sample Output 1

21
530
15
1320
10
