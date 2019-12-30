### Feedback for Lab 10

Run on October 19, 07:44:38 AM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		213d29dd2c8029437bc1ee19b341bb6f093927eb	refs/heads/devel

		6851b9f00e4e284128d7a6bc36928d9a7d5a4a00	refs/heads/fix/01-compilation-errors

		711965787aff64888bcfa8d32334696be7502f21	refs/heads/fix/02-enhancement

		f6a36ce928d34654a6fa93e7f67aeeee6f30fb5a	refs/heads/master



+ Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-enhancement


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Nick Karlovich] 2019-10-18 (HEAD -> devel, origin/devel) docs(Doxyfile): lab10 added Doxygen documentation - Added mainpage.h
- Created docs folder and Docs within


		[Nick Karlovich] 2019-10-17 Merge branch 'fix/02-enhancement' into devel 

		[Nick Karlovich] 2019-10-17 (origin/fix/02-enhancement, fix/02-enhancement) fix(passenger.cc): fix #2 implemented stub passenger class - fixed update(), GetTotalWait(), and IsOnBus()


		[Nick Karlovich] 2019-10-17 Merge branch 'fix/01-compilation-errors' into devel 

		[Nick Karlovich] 2019-10-17 (origin/fix/01-compilation-errors, fix/01-compilation-errors) fix(src/local_simulator.cc): fix #1 fixed pointer errors - changed pointer to use correct defreference . instead of -> 

		[Nick Karlovich] 2019-10-17 Merge branch 'support-code' 

		[Nick Karlovich] 2019-10-17 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-F19/csci3081-shared-upstream into support-code 

		[Nick Karlovich] 2019-10-17 cleanup 

		[Nick Karlovich] 2019-10-16 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-f19/repo-karlo015 

		[Nick Karlovich] 2019-10-16 fixed make commands 



		[Nick Karlovich] 2019-10-16 fixed lab09 passenger.cc and stop.cc 



		[Nick Karlovich] 2019-10-13 Merge branch 'master' of https://github.umn.edu/umn-csci-3081-f19/repo-karlo015 

		[Nick Karlovich] 2019-10-13 added build/ folder to gitignore 



		[Nick Karlovich] 2019-10-13 merge change 

		[Nick Karlovich] 2019-10-13 Merge branch 'support-code' of https://github.umn.edu/umn-csci-3081-F19/csci3081-shared-upstream into support-code 





















+ Pass: Check git commit history
Sufficient commits (found=18,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 2)

[CLOSED issue #2] :  enhancement [bug] @karlo015

[CLOSED issue #1] :  compilation-errors [bug] @karlo015





+ Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #2] :  enhancement [bug] @karlo015

[CLOSED issue #1] :  compilation-errors [bug] @karlo015

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Pass: Check that file "makefile" exists.

+ Pass: Check that make compiles.



