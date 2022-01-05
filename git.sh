#!/bin/bash

read -p 'file to add: ' file
read -p 'Enter commit message: ' message 

echo $file
echo $message

git add $file
git commit -m "$message"
git push
