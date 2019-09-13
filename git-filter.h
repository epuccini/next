#!/bin/sh

git filter-branch --env-filter '

an="$GIT_AUTHOR_NAME"
am="$GIT_AUTHOR_EMAIL"
cn="$GIT_COMMITTER_NAME"
cm="$GIT_COMMITTER_EMAIL"

if [ "$GIT_COMMITTER_EMAIL" = "Edward.Puccini <Edward.Puccini@partner.bmw.de>" ]
then
    cn="Edward Puccini"
    cm="edward@Edwards-MacBook-Air.local"
fi
if [ "$GIT_AUTHOR_EMAIL" = "Edward.Puccini <Edward.Puccini@partner.bmw.de>" ]
then
    an="Edward Puccini"
    am="edward@Edwards-MacBook-Air.local"
fi

export GIT_AUTHOR_NAME="$an"
export GIT_AUTHOR_EMAIL="$am"
export GIT_COMMITTER_NAME="$cn"
export GIT_COMMITTER_EMAIL="$cm"
'
