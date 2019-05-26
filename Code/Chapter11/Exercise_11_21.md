练习11.21：假定word_count是一个string到size_t的map，word是一个string到size_t的map，word是一个string，解释下面循环的作用：

```
while (cin >> word)
	++word_count.insert({word, 0}).first->second;
```

---

循环不断从标准输入读入单词（字符串），直至遇到文件结束或错误。

每读入一个单词，构造pair{word，0}，通过insert操作插入到word_count中。insert返回一个pair，其first成员是一个迭代器。若单词（关键字）已存在于容器中，它指向已有元素；否则，它指向新插入的元素。

因此，.first会得到这个迭代器，指向word对应的元素。继续使用->second可获得元素的值的引用，即单词的计数。若单词是新的，则其值为0，若已存在，值为之前出现的次数。对其进行递增操作，即完成将出现次数加1。
