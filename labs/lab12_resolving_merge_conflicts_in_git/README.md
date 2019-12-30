The objective of this lab is to show you how to resolve a merge conflict in git. 
Merge conflicts occur when the same portions of a file or files is/are changed in different ways , and then the change or changes
are committed in two different repositories (for example, your repository on the umn github server (github.umn.edu), 
and the clone of your git repository on the CSELabs machines, or csci-shared-upstream on the github server and your repository
on the CSELabs machines) - and then a merge is attempted via a git pull or git merge.

See the following link for a more complete discussion
(via tutorial) on merging with git: **https://www.atlassian.com/git/tutorials/using-branches/git-merge**

Merge conflicts usually occur when multiple people are working on the same repository - which can occur in this class when
instructors distribute or change code in shared-upstream that you have altered and committed in your repository 
and then you attempt to pull and merge from shared-upstream, for example. 
(There are other ways you can created them by yourself as well...)

To resolve a merge conflict, we'll have you create one first, and then resolve it. Complete the following 
to create the merge conflict.

Start by logging into a machine with a remote version of your repository 
(for example, a CSELabs machine). Then change directory into your repository and get the latest version of 
csci3081-shared-upstream repository (which contains this lab, lab12) as you have been doing since lab 2:

1) git checkout support-code
2) git pull upstream support-code
3) git checkout devel
4) git merge support-code
5) Go to the lab12 folder
6) Edit the file MergeIssue.cc
7) Add a comment to first line in the file:  // Here is a comment
8) Save MergeIssue.cc and exit your editor
9) git add MergeIssue.cc
10) git	commit
11) git	push to your repo on the github server (github.umn.edu)

12) **Next, use your browser to go to your repository on the umn github server (github.umn.edu)**
13)	Navigate to the lab12 directory / folder (in your repository on the umn github server)
14)	In your repository on the github.umn.edu server, edit the file: MergeIssue.cc
15)	Change comment in the first line in the file to :  // Changed comment on server
16)	Commit the changes on the Server (github.umn.edu)

17) **Next, return to your remote repository (for example, the copy on the CSELabs machine)**
18) Navigate to the lab12 directory / folder
19) Edit the file: MergeIssue.cc
20)	Change comment in the first line in the file to :  // Changed comment on remote repository
21)	Save the file and exit your editor
22)	git add MergeIssue.cc
23)	git commit

**NOTE, you now have two different versions of the same file located on different instances of your repository
so, when you attempt a merge, git will reject the merge and indicate that you have a merge conflict**

24) From your remote repository on the CSELabs machine: git pull 

** Git will indicate you have a merge conflict and the file (or) files in which the merge conflict has occured**

** Next, resolve (fix) the merge conflict **

25)	Edit the file MergeIssue.cc in your remote repository on the CSELabs machine
26)	Locate the angle brackets in the file <<<<        >>>>
27)	The brackets show location or locations of the merge conflict (or conflicts).
28)	Select one of the comments, delete the other comment, and get rid of (that is, delete) the angle brackets
29)	Save the file and exit your editor
30) git add MergeIssue.cc
31)	git commit
32)	git push
33) **You have resolved the merge conflict!!!**

A couple of other helpful commands for dealing with merge conflicts include:

git status  
git reset  
git reset --hard HEAD  

#### However, you should read about how the variants of the reset command work before using them!!!!!!
**Do the tutorial here: https://www.atlassian.com/git/tutorials/undoing-changes/git-reset
to help futher your understanding**

## Congratulations, you have completed Lab 12!
