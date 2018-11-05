1.在需要建立git仓库的路径右键点击Git base Here
2.输入git init // 建立本地仓库，仓库是一个管理所有版本的一个容器
建立本地仓库后，ls -a可以看到.git文件夹，即说明git本地仓库建立成功。
3.输入git add // 此时是将需要进行版本控制的文件加入仓库index，使这些文件
//被git跟踪，以便之后的记录修改。输入git add . 这个.表示当前路径，可以把当前
//路径下的全部文件加入到本地仓库，-A也可以实现全部加入，也可以单独加入单个文件。
4.输入git commit -m"the first commit" //将修改提交到本地仓库。

5.建立仓库后会有一条默认主分支：master
6.输入git branch new_branch// new_branch的内容完全拷贝于master分支，但在new_branch
//上面的修改不影响主分支master。
7.输入git checkout new_branch，可以选择到new_branch分支，在其上面进行修改文件对master无影响。
//6,7两部可以合为一步，git checkout -b new_branch。
8.在new_branch分支上修改后，若此时需要离开此分支，转到其他分支，可以先进行提交new_branch分支的修改。
git commit -m"the first new_branch commit"。
9.此时可以通过git status查看该分支各文件的状态，如果有修改后未提交，或者新增文件则均会高亮显示。
10.输入git checkout master选择master分支，此时：1.工作目录下的文件会转成你之前提交的master分支的状态。2.对工作
目录下的文件进行修改就是对master分支进行操作，不影响new_branch分支。
----------------------------------------------------------------------

上述1-10个步骤即是基本本地版本控制的步骤。
接下来即是如何将本地仓库推送push到远程仓库（需要先在Github,Gitlab等之类的项目托管平台建立远程仓库）

1.输入git remote add lwg17 git@github.com:/2017210698/test.git。如果提示"remote lwg17 already exists"，输入
git remote rm lwg17 删除已关联的错误远程仓库(其中，lwg17是远程仓库的名称)，然后重新执行以上操作再次关联。
2.输入git push -u lwg17 master,将本地仓库的master分支推送(push)到远程仓库。 // push 成功后，刷新Github，可以看到远程仓库
//多出来刚刚push的文件。-u参数是首次push需要加。
// git push 命令用法。 git push <远程主机名><本地分支名>：<远程分支名>
// git push lwg17,表示将当前分支推送到lwg17远程主机对应的分支。如果lwg17当前分支只有一个追踪分支，那么主机名lwg17都可以省略
//git push 如果当前分支与多个主机存在追踪关系，那么此时-u选项就会指定一个默认主机，后续push时就可以不加任何参数。
// git push -u lwg17 master,将本地的master分支推送到lwg17远程主机，同时指定lwg17为默认远程主机，后面可以不加任何参数。
// 不带任何参数的git push，默认只推送当前分支，这叫做simple分支。
// git push origin master,将本地的master分支推送到origin远程主机的master分支，如果远程的master分支不存在则会被新建。
// git push origin :master,如果省略本地分支名，则表示删除指定的远程分支，因为这等同于推送一个空的本地分支到远程分支。
// git push origin --delete master,表示删除origin主机的master分支。
// git push origin，如果本地分支和远程origin主机分支对应，存在追踪关系，则本地分支和远程分支都可以省略。
// git push，如果本地当前分支只有一个追踪分支，那么远程主机名也可以省略。
// git push -u origin master,将本地的master分支推送到origin远程主机的master分支，若origin没有master分支则自动创建master
//分支，同时指定origin为默认主机，后面就可以不加任何参数的使用git push了。不带任何参数的git push，默认只推送当前分支，simple方式。还有
//一种matching方式，会推送所有



git branch 用法
1.git branch -r，查看远程分支。
2.git clone git@github.com:2017210698/test.git,默认只clone远程主机的master分支，通过查看远程分支，利用git clone -b lwg17可以指定下载lwg17分支代码。
