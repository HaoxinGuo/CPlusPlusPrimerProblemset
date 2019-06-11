#! /bin/bash

# 自动编译源文件的脚本，使用方法：sh build.sh

all_md_files=`ls *.md`
#pandoc $all_md_files -o example.pdf --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter

main(){
#pandoc $all_md_files -o example.pdf --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter
#pandoc $all_md_files -o example.tex --from markdown --template eisvogel1 --latex-engine=xelatex -N --listings -V CJKmainfont='Microsoft YaHei' -V book --top-level-division=chapter

pandoc $all_md_files -o guo.pdf  --latex-engine=xelatex --template=template --title-prefix=guo --toc --listings --number-sections
}

main