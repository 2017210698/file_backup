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
--------------------------------------------------------
git push, 从本地向指定的远程仓库推送的相关操作。

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
// git push origin :master,如果省略本地分支名，则表示删除指定的远程分支，因为这等同于推送一个空的本地分支到远程分支。第一分支不可删除。
// git push origin --delete master,表示删除origin主机的master分支。在删除远程分支时，默认的default branch不能删除，要删除的话
// 必须在远程主机上修改default branch,方法是在远程主机上找到repositories->settings->branchs->default branch->update
// git push origin，如果本地分支和远程origin主机分支对应，存在追踪关系，则本地分支和远程分支都可以省略。
// git push，如果本地当前分支只有一个追踪分支，那么远程主机名也可以省略。
// git push -u origin master,将本地的master分支推送到origin远程主机的master分支，若origin没有master分支则自动创建master
//分支，同时指定origin为默认主机，后面就可以不加任何参数的使用git push了。不带任何参数的git push，默认只推送当前分支，simple方式。还有
//一种matching方式，会推送所有
3.备注：push到远程主机仓库之前，一定要git add file.txt， git commit -m"push file.txt",git push -u file_backup lwg，否则推送不上去。
---------------------------------------------------------------------------------------------------------
删除远程主机仓库文件的方法
1.git rm -r --cached file -> git commit -m"delete file" -> git push file_backup lwg 删除远程主机仓库lwg分支的file文件。
2.也可以先将要删除的远程主机文件pull下来，然后再本地删除，而后push上远程主机git pull file_backup lwg->git rm file->git commit -m"del file"->git push file_backup lwg
--------------------------------------------
删除本地仓库文件的方法
1.git rm --cached file,删除的是本地仓库中的文件，且在本地工作区的文件会保留不再与远程仓库发生跟踪关系，如果本地仓库文件也要删除，则用git rm file。
2.具体方法如下：git rm file->git add .->git commit -m"del file"->git push file_backup lwg.
3.也可以rm file->git add.->git commit -m"del file"->git push file_backup lwg

-------------------------------------------------------------

git branch 用法
1.git branch -r，查看远程分支。git branch -a，查看所有分支。然后直接git checkout lwg即可下载lwg分支。
2.git clone git@github.com:2017210698/test.git,默认只clone远程主机的master分支，通过查看远程分支，
// 利用git clone -b lwg,  git checkout lwg可以指定下载lwg分支代码。
3.也可以先在本地建立一个分支，建议名称和远程想要同步的分支名称一样。
// git branch lwg 建立一个名字一样的分支
// git checkout lwg 切换到这个本地分支
// 接下来建立上游分支的关联，由于命令较长，可以先git pull，会有提示如何关联。
// git pull 会有提示关联方法：git branch --set-upstream-to=origin/lwg lwg,然后再git pull即可。
4.git branch，查看创建分支。
5.git branch -d,强行删除分支。
6.git checkout，切换分支，git checkout -b,创建且切换分支。


------------------------------------------------------------------

1.git checkout . // 本地所有修改的，没有提交的，都返回到原来的状态。
2.git stash //把所有没有提交的修改暂存到stash里面，可以用git stash pop恢复。
3.git reset --hard HASH // 返回到某个节点，不保留修改。
4.git reset --soft HASH // 返回到某个节点，保留修改。

----------------------------------------------
1.git reflog,查看所有提交的log,可以查看每次变动的版本号。
2.git log,查看每次变动的详细情况。
3.git checkout -- file.txt,可以放弃对没有git add.的文件的修改。若此时已经git add .,把文件放置在暂缓区了，
可以使用git reset HEAD file.txt命令重新放入工作区，而后使用git checkout -- file.txt，放弃对其的修改。
4.git reset --hard af1b(af1b是对应的版本号)。
5.git diff HEAD -- file，查看最新版本的文件与之前的file文件的对比。

-----------------------------------------------------------------
生成密钥配置

1.ssh -keygen -t rsa -C "youremail@example.com",默认三个回车后即可在命令目录中生成公钥.pub和私钥文件。将.pub文件复制到github上就可以了。
2.git remote add origin git@github.com:2017210698/file_backup.git，关联本地目录到远程库。
3.git push -u origin,第一次推送master分支中所有内容，-u参数是将本地的master分支推送到远程库中的master,且进行关联，以后可以直接git push.
4.git clone git@github.com:2017210698/file_backup.git,可以从远程仓库克隆岛本地仓库。
5.git merge,合并某分支到当前分支，不建议使用
6.git log --graph,查看分支情况。
7.在团队开发中最后分为三条分支，一条是master主分支，必须保持稳定；一条是dev分支，时开发合并的，
在发布的时候将dev和master合并发布，而平时就可以只在个人分支和dev分支合并测试。



------------------------------------------------------------
git remote 命令，每个远程主机都必须有一个主机名用此管理

1.git remote -v/--verbose
2.git remote add name url,增加名为name的远程仓库，一旦添加以后可以用别名代表远程版本库地址。// git remote add joey git@github.com:2017210790/file_backup.git
3.git remote remove name // git remote remove joey
4.git remote rename old_name new_name,// git remote rename joey nike,重新命名
5.git remote show 主机名，// git remote show joey,查看指定主机的详细信息。

----------------------------------------------------------------
git push, 从本地向指定的远程仓库推送的相关操作。

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
// git push origin :master,如果省略本地分支名，则表示删除指定的远程分支，因为这等同于推送一个空的本地分支到远程分支。第一分支不可删除。
// git push origin --delete master,表示删除origin主机的master分支。在删除远程分支时，默认的default branch不能删除，要删除的话
// 必须在远程主机上修改default branch,方法是在远程主机上找到repositories->settings->branchs->default branch->update
// git push origin，如果本地分支和远程origin主机分支对应，存在追踪关系，则本地分支和远程分支都可以省略。
// git push，如果本地当前分支只有一个追踪分支，那么远程主机名也可以省略。
// git push -u origin master,将本地的master分支推送到origin远程主机的master分支，若origin没有master分支则自动创建master
//分支，同时指定origin为默认主机，后面就可以不加任何参数的使用git push了。不带任何参数的git push，默认只推送当前分支，simple方式。还有
//一种matching方式，会推送所有
3.git push joey,提示当前分支没有upstream分支，下面了解下什么是upstream分支， git push --set-upstream joey master
4.如果某一个库如joey库中的分支test被push到另一个远程库，例如远程仓库server库中的分支main,那么main就是test的upstream,而test是main的downstream。
此时，1）对于从远程库中clone或fetch得到的本地分支，都在远程库中有一个upstream分支。
	 2）对于在本地新建的本地分支，如果执行git push origin branch_name是不会为本地分支branch_name设定远程的upstream的，
	 	此时需要自己设定，git branch --set-upstream-to=xx(upstream分支的名称)。
5.但是push的时候通过-u参数来设置更为方便，一旦设置成功以后可以直接用git push命令来推送了。如果当前分支与多个主机存在追踪关系，则可以使用-u选项指定一个默认主机。
	至于其中的默认推送规则是有git config中的push.default属性决定。Git2.0以后默认规则是simple。
6.git push --all joey(远程主机名)，将所有本地分支都推送到joey远程主机，包括本地所有分支以及商贸的修改，但假如此时服务器上的版本更新了，就可能push不成功，需要我们先更新代码。
7.git push origin --tags, git push不会推送表情tag,除非使用--tags选项。
--------------------------------------------------------------------------------

git stash,当有紧急工作时，又不想commit现在做一半的工作，就用git stash，然后可以切换到其他分支进行紧急工作。
1.当使用过一个git stash后，切换到另一个分支，且仍未完成工作，也需要保持它的工作现场，再次使用git stash，其队列中有两个工作现场。
2.git stash list,可以查看stash队列。
3.在一个分支上想要恢复某一个工作现场，先使用git stash list，查看工作现场队列，确定要恢复哪个工作现场到当前分支。
	git stash list->git stash pop stash@{num},num就是你要恢复的工作现场的编号。
4.git stash clear,可以清空stash队列。
5.git stash pop命令是恢复stash队列中最上层的那个工作现场，num=0,stash@{0}，其对应的现场在stash中删除。
6.git stash apply stash@{num},其不在stash队列中删除工作现场，其他同pop命令。
