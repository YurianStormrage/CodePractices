#!/bin/zsh
[[ ! $# -lt 1 ]] || ! echo -e "\e[31merror: \e[mtitle not specified"

source ~/.zshrc

# id=${1%\.*}
# title=$2
# res=${3:-res.md}
title=$1
res=${2:-res.md}

src=./crawler.py

echo -e "\e[32mCrawling:\e[m" $title

[[ ! -f $res ]] || ! echo -e "\e[31merror\e[0m: File $(pwd)/$res exists" || exit 1

echo -ne "\e[33m"
python3 $src $title $res | tee /tmp/leetcode_crawler_tmp.txt

if [[ $? != 0 ]]; then
    echo "\e[31merror\e[0m: failed at running crawler.py"
    if [[ -f $res ]]; then
        echo -e "\e[32mDeleted\e[0m $res"
        rm $res
    fi
    exit 1
fi
echo -ne "\e[0m"

out=$(cat /tmp/leetcode_crawler_tmp.txt)

id=$(echo $out | sed -ne '/questionFrontendId: /{s/.*questionFrontendId: //; s/\([0-9]+\).*/\1/; p; q}')

if [[ -d $id ]]; then
    echo -e "Directory \e[34m$(pwd)/$id/\e[0m exists"
    if [[ -f $id/readme.md ]]; then
        echo -e "\e[31merror\e[0m: File $(pwd)/$id/readme.md exists"
        echo -e "\e[32mDelete file \e[34m$res\e[0m"
        rm $res
        exit 1
    fi
else
    echo -e "\e[32mCreate directory \e[34m$id\e[0m"
    mkdir $id
fi

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
