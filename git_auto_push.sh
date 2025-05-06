#!/bin/bash

# 确保脚本在一个 Git 仓库内运行
if [ ! -d .git ]; then
    echo "错误：当前目录不是 Git 仓库！"
    exit 1
fi

# 查看 Git 状态
echo "查看当前的更改状态..."
git status

# 添加所有更改到暂存区
echo "添加所有更改到暂存区..."
git add .

# 提交更改
echo "请输入提交信息："
read commit_message
git commit -m "$commit_message"

# 推送更改到远程仓库
echo "推送更改到远程仓库..."
git push origin main

echo "所有更改已成功提交并推送到 GitHub！"
