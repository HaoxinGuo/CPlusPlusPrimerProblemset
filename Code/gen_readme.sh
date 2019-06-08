# 生成README.md文件

#! /bin/bash

old_dir=$(pwd)
readme_file=${old_dir}/README.md

#######################################################################

# 设置每一个章节名字

get_all_Chapterapters()
{
cat << !CHAPTERS!
第1章_开始
第2章_变量和基本类型
第3章_字符串、向量和数组
第4章_表达式
第5章_语句
第6章_函数
第7章_类
第8章_IO库
第9章_顺序容器
第10章_泛型算法
第11章_关联容器
第12章_动态内存
第13章_拷贝控制
第14章_操作重载与类型转换
第15章_面向对象程序设计
第16章_模板与泛型编程
第17章_标准库特殊设施
第18章_用于大型程序的工具
第19章_特殊工具与技术
!CHAPTERS!
}

Chapterapters=$(get_all_Chapterapters)

######################################################################

# 生成一个章节练习的md文本

gen_Exercise_txt()
{
	Chapterapter_name=$1				# 章节名
	Chapterapter_name=${Chapterapter_name/_/ }			# 取消下划线

	Chapter_dir=$(ls -d $2*)			# 章节路径
	n_Chapter=$3					# 第几章

	echo "$Chapterapter_name $Chapter_dir"

	cd $Chapter_dir

	Exercise_files=$(ls -d Exercise*); # 所有的练习文件，包括目录
	echo "## $Chapterapter_name" >> $readme_file
	echo >> $readme_file
	echo "|A|L|L|E|X|E|" >> $readme_file
	echo "| :-: | :-: | :-: | :-: | :-: | :-: |" >> $readme_file # 居中
	
	num=0	# 第几个练习
	for Exercise_file in $Exercise_files; do

		num=$((num + 1))

		# Exercise_1_01a.cpp --> 01a.cpp --> 1a.cpp --> 1a --> 练习1.1a
		tab_name=${Exercise_file##*_}
		tab_name=${tab_name##0}
		tab_name=${tab_name%%.*}
		tab_name=练习$n_Chapter.$tab_name

		echo -e "|[$tab_name]($Chapter_dir/$Exercise_file \"./$Chapter_dir/$Exercise_file\")\c" >> $readme_file

		# 6列一行
		if [ $((num % 6)) = "0" ]; then
			echo "|" >> $readme_file
		fi
	done

	if [ $((num % 6)) != "0" ]; then
		echo "|" >> $readme_file
	fi
	
	echo >> $readme_file

	cd ..
	return 0
}

######################################################################

# 生成一个章节的案例代码的文本

gen_example_txt()
{
	Chapter_dir=$(ls -d $1*)		# 章节路径

	cd $Chapter_dir
	example_files=$(ls -d example* 2> /dev/null); # 所有的案例文件，包括目录

	if [ "$example_files" = "" ]; then
		cd ..
		return 0
	fi

	echo "### 案例代码" >> $readme_file
	echo >> $readme_file

	for file in $example_files; do
		grep_file=$file
		if [ -d $file ]; then
			grep_file=$file/main.cpp
		fi

		# // example: 数组形参（p193） --> 数组形参（p193）
		desc=$(grep "// example" $grep_file)
		desc=${desc#*: }

		if [ "$desc" != "" ]; then
			echo "- [$desc]($Chapter_dir/$file)" >> $readme_file
			echo >> $readme_file
		fi
	done

	cd ..
	return 0
}

######################################################################

gen_readme()
{
	n_Chapter=0 		# 当前处理的第几章
	for Chapterapter_name in $Chapterapters; do
		n_Chapter=$(($n_Chapter + 1))

		cur_Chapter=Chapter # 章节的英文路径开头

		if [ $n_Chapter -lt 10 ]; then
			cur_Chapter=Chapter0
		fi

		cur_Chapter=${cur_Chapter}$n_Chapter

		gen_Exercise_txt $Chapterapter_name $cur_Chapter $n_Chapter
		gen_example_txt $cur_Chapter
	done

	return 0
}

main()
{
	rm -f $readme_file
	touChapter $readme_file

	echo '# C++ Primer第五版学习笔记' >> $readme_file
	echo -e '\n学习环境：Windows 10' >> $readme_file
	echo -e '\n---' >> $readme_file
	echo >> $readme_file

	gen_readme

	return 0
}

main

exit 0
