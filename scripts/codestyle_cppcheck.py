#!/usr/bin/env python
# coding=utf-8
__doc__ = """
该脚本在post-commit钩子中被调用
当用户执行git commit的时候会在本地触发调用
在.git/hooks/post-commit添加如下内容即可

python scripts/codestyle_cppcheck.py

每次commit结束之后，会有一个.log文件生成，其中包含各更改文件的代码风格检查中的问题

"""
import sys
import subprocess


__author__ = "caowenlong92@gmail.com"


class GitTrigger(object):

    def __init__(self):
        '''
        初始化文件列表信息
        '''
        self.file_list = []

    def get_push_file_list(self):
        '''
        git diff命令获取当次提交的文件列表
        文件的路径为相对于版本库根目录的一个相对路径
        '''
        rev = subprocess.Popen(
            'git diff --name-only HEAD~ HEAD', shell=True, stdout=subprocess.PIPE)
        push_list = rev.stdout.readlines()
        self.file_list = [x.strip() for x in push_list]
        return self.file_list


def check_update_protector(files):
    is_protector = lambda x: x.find("protector/") > -1
    for f in files:
        if is_protector(f):
            print('\033[1;31m')
            print('*' * 77)
            print("  you have update files in protector, remember update protector/README.txt ")
            print('*' * 77)
            print('\033[0m')
            return

def main():
    verbose = 3
    output = "emacs"
    positive_fliter = []
    negative_filter = ["legal/copyright"]  # reference cpplint.py line:274
    counting = "detailed"
    exclude = ["3rdparty/*"]
    linelength = 80
    recursive = False
    extensions = "hpp,cpp,h"
    root = ""

    call_str = "python scripts/cpplint.py "
    if verbose:
        call_str = "{} --verbose={}".format(call_str, verbose)

    if output:
        call_str = "{} --output={}".format(call_str, output)

    if positive_fliter:
        call_str = "{} --filter={}".format(call_str,
                                           ",".join(map(lambda x: "+" + x, positive_fliter)))

    if negative_filter:
        if positive_fliter:
            call_str = "{},{}".format(call_str, ",".join(
                map(lambda x: "-" + x, negative_filter)))
        else:
            call_str = "{} --filter={}".format(
                call_str, ",".join(map(lambda x: "-" + x, negative_filter)))

    if counting:
        call_str = "{} --counting={}".format(call_str, counting)

    if recursive:
        call_str = "{} --recursive".format(call_str)

    if exclude:
        for exc_path in exclude:
            call_str = "{} --exclude={}".format(call_str, exc_path)

    if root:
        call_str = "{} --root={}".format(call_str, root)

    if linelength:
        call_str = "{} --linelength={}".format(call_str, linelength)

    if extensions:
        call_str = "{} --extensions={}".format(call_str, extensions)

    t = GitTrigger()
    files = t.get_push_file_list()
    check_update_protector(files)
    call_str = "{} {}".format(call_str, " ".join(files))
    p = subprocess.Popen(call_str, shell=True,
                         stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    pipe = p.stderr.readlines()
    with open("code_style_googlecppcheck.log", "w+") as fd:
        fd.writelines(pipe)

    print "code style cppcheck success"


if __name__ == "__main__":
    main()
