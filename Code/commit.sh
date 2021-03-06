#! /bin/bash

# 提交代码到github

clear_build() {
	for d in ./Chapter*; do
		cd $d
			if [ -f build.sh ]; then
				sh build.sh clear
			fi
		cd ..
	done

	%cd labs
	%sh build.sh clear
	%cd ..
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
	git commit -m "commit"

	echo "Committing ..."
	git push origin master
}

main() {

	if [ "$1" = "gen" ]; then
		clear_build
		sh ./gen_readme.sh
	fi

	if ! show_status; then
		return 0
	fi

	echo -e "--------------------------\nIs it ok [y/n]: \c"
	read answer

	if [ "$answer" == "y" ]; then
		commit
	fi
}

main $*

exit 0
