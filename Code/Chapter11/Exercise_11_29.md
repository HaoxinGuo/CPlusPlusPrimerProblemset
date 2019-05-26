练习11.29：如果给定的关键字不在容器中，upper_bound, lower_bound和equal_range分别会返回什么？

---

upper_bound和lower_bound返回相同的迭代器——指向一个不影响排序的关键字插入位置。如果给定的关键词比容器中的任何关键词都大，则此位置是容器的尾后位置end。

equal_range中的两个迭代器都指向可以插入的位置，构成一个空范围。
