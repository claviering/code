#/*************************************************************************
#	> File Name: pushEveryDay.sh
#	> Author: 
#	> Mail: 
#	> Created Time: Thu 07 Jul 2016 10:16:19 PM CST
# ************************************************************************/
# edit hello.cpp and git add commit push it
cd ~/code/fun/
vim hello.cpp
expect
#和用户交互
git add hello.cpp 
git commit -m "hello"
git push origin master
