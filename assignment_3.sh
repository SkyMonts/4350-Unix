#!/bin/bash
printf  "\n\nCS 4350 – Unix Systems Programming	
NAME: Sky Monts																						
Serial Number: 20
Functions and Arrays
Assignment Number: 3
Due Date: 10 / 7 / 2019
The function of this script is to:
1. List	detailed list of all files in your directory. Redirect the output to zlsCommandFiles.txt
2. Create directory by checking its existence
3. Test	if File Exist.
4. Append “Learning Scripts and Shell Programming“ to an existing File.	
5. Rename an existing File.	
6. Delete an existing File.	
7. Delete an existing Directory.	
8. Parse Current Date
9. Display a calendar for a specific month / year
15. Exit\n\n"

functOne(){
	ls > zlsCommandFiles.txt
	echo "zlsCommandFiles.txt is created"
	echo
}

functTwo(){
	if [[ -d $1 ]]; then
		echo "Directory \"$newDir\" already exists"
	fi
	echo "$1 was created.."
	mkdir $1
	echo
}

functThree(){
	if [[ -f $1 ]]; then
		echo "Number of lines and words: $(< "$f" wc -l) $(< "$f" wc -w)"
		echo "File Content:"
		cat $1
	else
		echo "File does not exist. Creating file......."
		touch $1
	fi
	echo
}

functFour(){
	if [[ -f $1 ]]; then
		printf "File Content Before Append:\n"
		cat $1
		printf "\nLearning Scripts and Shell Programming\n" >> $1
		printf "\nFile Content After Append:\n"
		cat $1
	else
		printf "File \"$f\" does not exist\n"
	
	fi
	echo
}

functFive(){
	if [[ -f $1 ]]; then
		mv $1 $2
		printf "$1 is renamed to $2\n"
	else
		printf "File \"$1\" does not exist\n"
	fi
	echo
}

functSix(){
	if [[ -f $1 ]]; then
		rm $1 
		printf "$1 is deleted\n"
	else
		printf "File \"$1\" does not exist\n"
	fi
	echo
}

functSeven(){
	if [[ -d $1 ]]; then
		rm -d $1 
		printf "$1 is deleted\n"
	else
		printf "Directory \"$1\" does not exist\n"
	fi
	echo
}

functEight(){
	echo "Current Date is: $(date '+%a %b %m')"
	echo "Current Time is: $(date +"%H:%M:%S")"
	echo
}

functNine(){
	cal -m $1 $2
	echo
}

while : 
do
	printf "Enter your choice: "
	read choice

	case $choice in
		1)  functOne;;
		2) 
			printf "Enter name of directory: "
			read newDir
			functTwo $newDir;;
		3) 
			printf "Enter file name: "
			read f
			functThree $f;;
		4) 
			printf "Enter file name: "
			read f
			functFour $f;;
		5)
			printf "Enter file to be renamed: "
			read fileName
			printf "Enter the new name: "
			read fileNewName
			functFive $fileName $fileNewName;;
		6)
			printf "Enter The name of file to be deleted: "
			read fileName
			functSix $fileName;;
		7)
			printf "Enter The name of directory to be deleted: "
			read dirName
			functSeven $dirName;;
		8)
			functEight;;
		9)
			printf "Enter Month: "
			read month 
			printf "Enter Year: "
			read year 
			functNine $month $year;;
		15) break;;
		
		*)
			printf "Invalid choice\n";;
		
	esac
done