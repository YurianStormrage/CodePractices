#!/bin/zsh
source ~/.zshrc

id=${1%\.*}
title=$2
res=${3:-res.md}

echo -e "\e[32mCrawling:\e[m" $id. $title

[[ ! -f $res ]] || ! echo -e "\e[31merror\e[0m: File $(pwd)/$res exists" || exit 1

if [[ -d $id ]]; then
    echo -e "Directory \e[34m$(pwd)/$id/\e[0m exists"
    if [[ -f $id/readme.md ]]; then
        echo -e "\e[31merror\e[0m: File $(pwd)/$id/readme.md exists"
        exit 1
    fi
else
    mkdir $id
    echo -e "\e[32mCreated \e[34m$id/\e[0m"
fi

echo -ne "\e[33m"
python3 crawler.py $title $res

if [[ $? != 0 ]]; then
    echo "\e[31merror\e[0m: failed at running crawler.py"
    if [[ -f $res ]]; then
        rm $res
        echo -e "\e[32mDeleted\e[0m $res"
    fi
    exit 1
fi
echo -ne "\e[0m"

rc=0
sed -i "1i\---\ntitle: $title" $res
rc=$(($rc | $?))
sed -i "/^\(Hard\|Medium\|Easy\)/s/^/difficulty: /" $res
rc=$(($rc | $?))
sed -i "4i\date: $(date '+%Y-%m-%d %H:%M:%S')\nurl: https://leetcode.cn/problems/$title/\ntags:\n    - \n---" $res
rc=$(($rc | $?))
sed -i "9s/^/# [$id. /" $res
rc=$(($rc | $?))
sed -i "9s|$|](https://leetcode.cn/problems/$title/)\n## 描述|" $res
rc=$(($rc | $?))
sed -i "/^ $/d" $res
rc=$(($rc | $?))
sed -i '$a\\n## [思考](./code.cpp)' $res
rc=$(($rc | $?))

if [[ $rc != 0 ]]; then
    echo -e "\e[31merror\e[0m: failed at running command sed"
    if [[ -f $res ]]; then
        rm $res
        echo -e "\e[32mDeleted\e[0m $res"
    fi
    exit 1
fi

mv $res $id/readme.md
echo -e "\e[32mMoved\e[0m $res > $id/readme.md"
