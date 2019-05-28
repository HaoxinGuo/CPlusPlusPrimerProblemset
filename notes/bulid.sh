#! /bin/bash

# �Զ�����Դ�ļ��Ľű���ʹ�÷�����sh build.sh [rebuild | clear]

all_cpp_files=`ls *.md`
#pandoc $all_cpp_files -o example.pdf --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter

main(){
pandoc $all_cpp_files -o example.pdf --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter
pandoc $all_cpp_files -o example.tex --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter

}

main