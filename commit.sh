#! /bin/bash

# 提交代码到github

clear_build() {
	for d in ./Code/Chapter*; do
		cd $d
			if [ -f build.sh ]; then
				sh build.sh clear
			fi
	done
}

show_status() {
	if git status | grep 'nothing to commit'; then
		return 1
	else
		echo "Changed files: "
		git status -s -u
		return 0
	fi
}

commit() {
	git status
	git add .
	git commit -m $keycommit

	echo "Committing ..."
	git push origin master
}

main() {

	if [ "$1" = "gen" ]; then
		clear_build
		sh ./Code/gen_readme.sh
	fi

	if ! show_status; then
		return 0
	fi

	echo -e "--------------------------\nIs it ok [y/n]: \c"
	read answer

	if [ "$answer" == "y" ]; then
		echo -e "--------------------------\nPlease enter the commit key: \c"
		read keycommit
		commit
	fi
}

main $*

exit 0
