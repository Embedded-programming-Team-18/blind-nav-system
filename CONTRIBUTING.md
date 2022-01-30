# Contributor's Guide

'BLIND NAVIGATION SYSTEM' accepts PR's (pull requests) from **collaborators only**
only.

Issues can be submitted by any of the collaborators.

**Contents**

- [Getting Started](#getting-started)
- [Issues](#issues)
- [Pull Request](#pull-requests)
- [Code Review](#code-review)
- [Helpful Resources](#helpful-resources)

### Getting Started

1. It is advisable that you go through
    [GitHub For Beginners](http://readwrite.com/2013/09/30/understanding-github-a-journey-for-beginners-part-1/)
    **before** moving on to contribute on this project.

2.  Clone the project.
    [Help Guide to Clone a Repository](https://help.github.com/en/articles/cloning-a-repository)

3.  Create a branch specific to the issue you are working on.
    
    The project currently has 'main', 'develop' and 'gh-pages' branches.
    **gh-pages** handles GitHub pages and `.md` files.


    For clarity, name your branch accroding to the following: 
    - [X-x-x-x](#prefix-description) 
    The `X` is a broad name for the task and the `x-x-x` is a short description of the changes you're making. Examples include `create-LiDAR-class` or
    `add-uml-description-md`.

    Use the project issues and Asana board as a guide for branch names

5.  Use any text editor and make your changes. 
    
    'LINUX' is the recommended OS. If you can write `C++` on any other OS, this is OK.

6.  Add your modified
    files to Git, [How to Add, Commit, Push, and Go](http://readwrite.com/2013/10/02/github-for-beginners-part-2/).

    ```shell
    git add path/to/filename.ext
    ```

    You can also add all unstaged files using:

    ```shell
    git add .
    ```

    **Note:** using a `git add .` will automatically add all files. You can do a
    `git status` to see your changes, but do it **before** `git add`.

6.  Commit your changes using a descriptive commit message.

    ```shell
    git commit -m "Brief Description of Commit"
    ```

7.  Push your commits to your GitHub Fork:

    ```shell
    git push -u origin branch-name
    ```

8.  Submit a pull request.

    Within GitHub, visit the repository and you should see a banner
    suggesting that you make a pull request. Switch to **develop** branch and make the pull request to develop. While writing the pull request, add `Closes #XXX` in the message body where `#XXX` is the
    issue you're fixing. For example `Closes #42` would close issue `#42`.


### Issues

[Issues in GitHub?](https://docs.github.com/en/issues/tracking-your-work-with-issues/about-issues)

* To start working on this repo, check the issues tab and identify an issue to work on. 
* Check the comment thread to see if there is somebody already working to fix the issue.
* If no one is working on it, Leave a comment that you intend to work on the issue and assign yourself to it.

By doing this,
other people don't accidentally duplicate your effort.

*Note*: Every issue in this project has a **milestone** named as `sprint#number` where by each milestone is a weekly sprint.


### Pull Request

[What is a Pull Request?](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)

When you are ready to add you fix to an issue to the project, push your branch to the repo and create a pull request to **[develop]** branch.

*Here are possible questions:*
* What's this PR for or do?
* Where should the reviewer start?
* How should this be manually tested?
* Where's the documentation?
* Any background context you want to provide?
* What are the relevant ticket(s)?
* Screenshots of the design if it's available...

**Try to answer a least 4 of this questions in your pull requests**

### Code Review

The
[code review](contributors)
will be done by all contributors over an iteratively.

Once the team is confortable that the function is working fine, the work will be merged to develop.

This will be merged to main when the team is ready to make a relaese.

The reviewers should leave comments where necessary.

```
- [file name](file-name) - Indicate the file name for your comment
- [line numbers](line-numbers) - Indicate the line numbers for the comment so that the other person will understand.
```

### Helpful Resources

* [Pro GIT Book](https://git-scm.com/book/en/v2)

* [Try Git](https://try.github.io/)

* [Git/ Git Hub on Windows](https://www.youtube.com/watch?v=J_Clau1bYco)