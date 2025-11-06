#/bash/bin


echo "ENTER THE NAME OF ADDRESS BOOK: "
read fname
if [ -f $fname ]
then
	echo -e "ADDRESS BOOK ALREADY EXIST !!\n"
else
	echo -e "NAME\t\tID\t\tDOB\t\tMOBILE_NO\t\tSALARY\n" > $fname
	echo -e "ADDRESS BOOK CREATED SUCCESSFULLY !! \n"
fi

ch=0
while [ $ch -ne 7 ]
do 
	echo -e "ADDRESS BOOK : \n"
	echo -e "1]CREATE ADDRESS BOOK\n"
	echo -e "2]VIEW THE ADDRESS BOOK\n"
	echo -e "3]INSERT A RECORD\n"
	echo -e "4]DELETE A RECORD\n"
	echo -e "5]MODIFY A RECORD\n"
	echo -e "6]SEARCH A RECORD\n"
	echo -e "7]EXIT THE ADDRESS BOOK\n"
	echo -e "ENTER YOU CHOICE : "
	read ch	
case $ch  in
	1)
		echo -e "ENTER NO OF RECORDS YOU WANT TO ENTER: "
		read n
		for ((i=0;i<$n;i++))
		do
		echo -e  "ENTER THE NAME OF EMPLOYEE"
		read ename
		echo -e "ENTER ID OF EMPLOYEE"
		read eid
		echo -e "ENTER DOB OF EMPLOYEE"
		read edob
		echo -e "ENTER MOBILE_NO OF EMPLOYEE"
		read emob
		echo -e "ENTER SALARY OF EMPLOYEE"
		read esal
		echo -e "$ename\t\t$eid\t\t$edob\t\t$emob\t\t$esal" >> $fname
		done 
	;;
	3)
		echo -e  "ENTER THE NAME OF EMPLOYEE"
                read ename
                echo -e "ENTER ID OF EMPLOYEE"
                read eid
                echo -e "ENTER DOB OF EMPLOYEE"
                read edob
                echo -e "ENTER MOBILE_NO OF EMPLOYEE"
                read emob
                echo -e "ENTER SALARY OF EMPLOYEE"
                read esal
                echo -e "$ename\t\t$eid\t\t$edob\t\t$emob\t\t$esal" >> $fname
		;;
	2)
		cat $fname
		;;
	4)
		echo -e "ENTER EMPLOYEE ID TO BE DELETED"
		read eid
		if grep -qw $eid $fname
		then
			
			grep -wv $eid $fname >> temp 
			mv temp $fname
		else
		echo -e "RECORD DOES NOT EXIST"
		fi
		;;
	5)
		echo -e "ENTER EMPLOYEE ID TO BE MODIFIED"
                read eid
                if grep -qw $eid $fname
                then
                        
                        grep -wv $eid $fname >> temp
                        mv temp $fname
                echo -e  "ENTER THE NAME OF EMPLOYEE"
                read ename
                echo -e "ENTER ID OF EMPLOYEE"
                read eid
                echo -e "ENTER DOB OF EMPLOYEE"
                read edob
                echo -e "ENTER MOBILE_NO OF EMPLOYEE"
                read emob
                echo -e "ENTER SALARY OF EMPLOYEE"
                read esal
                echo -e "$ename\t\t$eid\t\t$edob\t\t$emob\t\t$esal" >> $fname
		echo -e "RECORD MODIFIED SUCCESSFULLY\n"
                else
                echo -e "RECORD DOES NOT EXIST\n"
                fi
                ;;
	6)
	        echo -e "ENTER EMPLOYEE ID TO BE SEARCHED"
                read eid
                if grep -qw $eid $fname
                then
                        grep -w $eid $fname
                       
                        echo -e "EMPLOYEE RECORD SEARCHED SUCCESSFULLY !!"
                else
                echo -e "RECORD DOES NOT EXIST"
                fi
                ;;
	7)
		echo -e "EXITING.....\n"
		;;
	*)
		echo -e "INVALID INPUT...\n"
		;;
esac
done
