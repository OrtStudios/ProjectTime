@echo off

echo pulling from github
git pull

cd Core
git pull
cd ..

echo adding changes
git add .

echo commiting
git commit -m "updated ProjectTime repository"

echo pushing to github
git push

echo finished commiting and pushing
