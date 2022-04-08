# Practice-addition-and-subtraction
这是一个程序，来辅助用户进行加减法练习
程序每次运行时，会一次输出10道简单的加减法练习题。毎输出1道题，等待用户输入其计算答案。题目难度限制在百以内的加减法，便于练习。
在这里，需要使用循环来实现。每轮循环输出随机生成的问题，如：“2+3=＂。接收用户的输入后，检查其正确性。并将检查结果存入相关变量便于循环后统计输出。
使用头文件 cstdlib 中的 rand 函数实现随机生成数字，并将随机生成结果取模，以限制其范围。
在10道题目全部解答完毕后，程序会给出用户答对与答错的题目个数，并给出答错的题目与其正确答案。且制定了相应赋分规则，向用户输出答题的最终得分。
PS1:在答題程序开始前，可以通过简单的输入输出交互，让用户确定题目的数量、难度（运算的大小范围及是否设计乘除）
PS2:实现统计用户回答每一道题的用时，并向用户输出答题平均用时与最短用时。
