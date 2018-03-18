# Chapter 01 Basic Concepts, SECU201-18S

## Task 01: Learn Git and Github basics
In the textbook (or the lecture 1 slides), you can find the source code of Example 1.1 (Selection sort).
You should type, build, and run the code under your Git local repository, and upload your code into this remote GitHub repository.
(You should not commit and push the executable binary to this remote Github repository!)
After this task, the path of your code should be https://github.com/rohnugu/secu201-18s/ch01/task01/selsort_201727####.c where # means a decimal digit so that 201727#### represents your student no.

You can easily find great Git/GitHub guides by googling, but the following links may reduce your burden:
1. git 윈도우용 설치 및 최소한의 기본 사용법 http://igotit.tistory.com/entry/Git-%EC%9C%88%EB%8F%84%EC%9A%B0%EC%9A%A9-%EC%84%A4%EC%B9%98
2. 완전 초보를 위한 깃허브 https://nolboo.kim/blog/2013/10/06/github-for-beginner/
3. git - 간편 안내서 https://rogerdudler.github.io/git-guide/index.ko.html
4. https://github.com/tadkim/infra/wiki/GitHub-::-%EA%B9%83%ED%97%88%EB%B8%8C-%EC%82%AC%EC%9A%A9%EB%B2%95-1

If you are not familiar with command-line user interface (CUI), consider to use the following GUI tools.
1. GitHub Desktop: https://desktop.github.com (Very easy, but you cannot work with other Git repository...)
2. Sourcetree: https://ko.atlassian.com/software/sourcetree (A widely used GUI Git client for Windows and Mac)
3. TortoiseGit: https://tortoisegit.org/ (Just for Windows but it is integrated with Windows Shell Interface - that is, you can use git in File Explorer.)

Some important comments:
* Since this repository is owned by the lecturer, you must let the lecturer know your GitHub ID (i.e., username). Please e-mail your GitHub ID to the lecturer. After the lecturer add your ID as a collaborator, you can push your code.
* Please the relative path (상대경로) of your local repository and the remote Github repository. For example, suppose that the root directory of your local repository is C:\johndoe\gitroot. Then you should write your code into C:\johndoe\gitroot\ch01\task01, since the root directory of the remote Github repository is https://github.com/rohnugu/secu201-18s.

## Task 02: Tower of Hanoi (Textbook Exercise 1.3.11)
The Tower of Hanoi is a well-known mathematical puzzle invented by the French mathematican Edouard Lucas in 1883. In this puzzle, there are three rods (막대) and a (given) number of stacked disks of different sizes. The puzzle starts with the disks in ascending order of size on one rod, i.e., the smallest at the top, so that it the disks make a conical shape. The goal of the puzzle is to move the entire stack to another rod, constraining the following rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upmost disk from one of the stacks and placing it on top of another stack.
3. No disk may be placed on top of a smaller disk.

It can be showed that the minimal number of moves required to solve a Tower of Hanoi puzzle is 2<sup><i>n</i></sup> - 1, where <i>n</i> is the number of disks. For example, when only one disk is given, the minimal number of moves is just one, when two disks are given, the minimal number is three. You can check <a href="https://en.wikipedia.org/wiki/Tower_of_Hanoi" target="_new">the Tower of Hanoi page from Wikipedia</a> to observe an animated solution of the puzzle.

So, in this task, you should design a 'recursive algorithm' to find the minimal number of moves for the Tower of Hanoi puzzle, and implement the algorithm as a simple C program. The 'required' input parameter for this algorithm is <i>n</i>, and the resulting output is clearly 2<sup><i>n</i></sup> - 1. Since the output is trivial, you should print the 'trace' of your moves to get the minimal number of moves. For example, suppose three disks are given in rod 1 and we should move the disks to rod 3. Then the trace could be:
* The upmost disk in rod 1 is moved to rod 3.
* The upmost disk in rod 1 is moved to rod 2.
* The upmost disk in rod 3 is moved to rod 2.
* The upmost disk in rod 1 is moved to rod 3.
* The upmost disk in rod 3 is moved to rod 1.
* The upmost disk in rod 3 is moved to rod 2.
* The upmost disk in rod 2 is moved to rod 3.
* Thus, the minimal number of moves is 7.

As said in the class, the design of this algorithm is not easy - you should carefully include 'additional' parameters in your recursive function. It is recommended to design and implement this algorithm without reading any solution. The resulting code should be located in this GitHub repository: https://github.com/rohnugu/secu201-18s/ch01/task02/hanoi_201727####.c where # means a decimal digit so that 201727#### represents your student no.
