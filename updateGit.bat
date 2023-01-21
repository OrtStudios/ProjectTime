@echo off

echo pulling from github
git pull

cd Core
git pull
cd ..

echo adding changes
git add .

cd Core
git add .
cd ..

echo commiting
git commit -m "updated ProjectTime repository"

cd Core
git commit -m "updated PT Core repository"
cd ..

echo pushing to github
git push

cd Core
git push
cd ..

echo finished commiting and pushing
