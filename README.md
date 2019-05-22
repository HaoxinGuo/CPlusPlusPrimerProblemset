# CPlusPlusPrimerProblemset
C++Primer课后习题练习
# Chapter01

# NotePad++配置Visual C++
cmd /k call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat" x86 & chdir /d "$(CURRENT_DIRECTORY)" & cl $(FILE_NAME) & del  "$(NAME_PART).obj" & echo Running: & "$(NAME_PART).exe" & PAUSE & EXIT
