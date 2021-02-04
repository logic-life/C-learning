# C++learning
寒假每日打卡

## **类型泄露常见方式**
```
//第一种情况，当给void指针释放内存时，会造成内存泄露
	void *str1 = new memory_leak_first('a', 3);
	memory_leak_first  *str2 = new memory_leak_first('c', 3);
	/*static_cast<memory_leak_first*>(str1)->~memory_leak_first();*/
	//硬释放，将void类型转化为memory_leak_first类型，然后显示指定析构函数
	delete str1;
	delete str2;
	//第二种情况，忘记给释放内存
	//set_new_handler(out_of_memory);
	//while (1) {
	//
	//	new int[1000];
	//
	//}
	//第三种情况，释放内存不完全
	/*Test* object1 = new Test[100];
	Test *object2 = new Test[100];
	delete[]object1;
	delete[]object2;*/
```
**内存泄露**：是因为由于调用了molloc或者new等内存操作的操作，但是缺少了对应的free和delete操作。为了判断是否内存泄漏，我们一方面可以使用Linux下的内存泄露检查工具
**Valgrind**,另一方面我们可以在写代码的时候添加内存申请和释放的统计功能，统计当前申请和释放的内存是否一致，以此来判断内存是否泄露。
