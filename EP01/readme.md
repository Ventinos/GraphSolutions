# Money Matters

*By Gunnar Kreitz* ![Flag of Finland](https://resources.beecrowd.com.br/gallery/images/flags/fi.gif) *Finland*

*from:* https://www.beecrowd.com.br/judge/en/problems/view/3215

**Timelimit: 1**

Our sad tale begins with a tight clique of friends. Together they went on a trip to the picturesque country of Molvania. During their stay, various events which are too horrible to mention occurred. The net result was that the last evening of the trip ended with a momentous exchange of “I never want to see you again!”s. A quick calculation tells you it may have been said almost 50 million times! Back home in Scandinavia, our group of ex-friends realize that they haven’t split the costs incurred during the trip evenly. Some people may be out several thousand crowns. Settling the debts turns out to be a bit more problematic than it ought to be, as many in the group no longer wish to speak to one another, and even less to give each other money. Naturally, you want to help out, so you ask each person to tell you how much money she owes or is owed, and whom she is still friends with. Given this information, you’re sure you can figure out if it’s possible for everyone to get even, and with money only being given between persons who are still friends.

## Input

The first line contains two integers, **N** (2 ≤ **N** ≤ 10000), and **M** (0 ≤ **M** ≤ 50000), the number of friends and the number of remaining friendships. Then **N** lines follow, each containing an integer **O** (−10000 ≤ **O** ≤ 10000) indicating how much each person owes (or is owed if **O** < 0). The sum of these values is zero. After this comes **M** lines giving the remaining friendships, each line containing two integers **X** and **Y** (0 ≤ **X** < **Y** ≤ **N** − 1) indicating that persons **X** and **Y** are still friends.

## Output

Your output should consist of a single line saying “POSSIBLE” or “IMPOSSIBLE”.

### Input Sample

## Input 1
5 3
100
-75
-25
-42
42
0 1
1 2
3 4

## Output 1
POSSIBLE

## Input 2
4 2
15
20
-10
-25
0 2
1 3

## Output 2
IMPOSSIBLE

*Nordic Collegiate Programming Contest 2009*

# Testing our solution:
* make sure to open the directory /EP01
* run ```make```
* run ```./main``` 
