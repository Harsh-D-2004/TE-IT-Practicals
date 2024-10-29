FILE_NAME=""

filename(){
	
	local filename=$1
	FILE_NAME=$filename

}

fileExists(){
	if [ -e $FILE_NAME ]; then
		return 0
	else
		return 1
	fi
}

createAddressBook(){

	if [ ! -e $FILE_NAME ]; then
		touch $FILE_NAME
	fi
	echo "| Name | Address | Phone |" > $FILE_NAME
}

viewAddressBook(){
	
	if ! fileExists; then
	
		if [ -s $FILE_NAME ]; then
		
			cat $FILE_NAME;
		else
			echo "Address Book is empty"
		fi
	else
		echo "Address Book does not exists"
	fi
}

insertRecord(){

	if ! fileExists; then
	
		read -p "Enter Name : " name 
		read -p "Enter Address : " address
		read -p "Enter Phone : " phone
		
		echo "| $name | $address | $phone |" >> $FILE_NAME
		
	else
		echo "Address Book does not exists"
	fi
	
}

updateRecord(){
	
	if ! fileExists; then
	
		read -p "Enter Name : " name
		
		if [ -z "$(grep -i "$name" AddBook.txt)" ]; then
			
			echo "$name not found"
			return
		fi
		
		sed -i "/$name/d" $FILE_NAME
		
		read -p "Enter Address : " address
		read -p "Enter Phone : " phone
		
		echo "| $name | $address | $phone |" >> $FILE_NAME	
	else
		echo "Address Book does not exists"
	fi
}

deleteRecord(){
	
	if ! fileExists; then
	
		read -p "Enter Name : " name
		
		if [ -z "$(grep -i "$name" $FILE_NAME)" ]; then
			
			echo "Record not found"
			return
		fi
		
		sed -i "/$name/d" $FILE_NAME
		
		echo "Record deleted successfully"
	else
		echo "Address Book does not exists"
	fi
}

searchRecord(){
	
	if ! fileExists; then
		
		read -p "Enter Name : " name
		
		if [ -z "$(grep -i "$name" $FILE_NAME)" ]; then
			
			echo "Record not found"
			return
		fi
		
		echo "Record found"
		grep -i "$name" $FILE_NAME
		
	else
		echo "Address Book does not exists"
	fi
}

main(){

	while true
	do
	
	echo "------------------------------------------------------------------------"
		
		echo "1) Create AddBook"
		echo "2) Insert Record"
		echo "3) Update Record"
		echo "4) Delete Record"
		echo "5) Search Record"
		echo "6) View Address Book"
		echo "7) Exit"
	echo "------------------------------------------------------------------------"	
		read -p "Enter Choice : " choice
	echo "------------------------------------------------------------------------"
		case $choice in
		
			1)
			echo "Create AddressBook"
			echo "Enter Filename : "
			read name
			filename "$name"
			createAddressBook
			;;
			
			2)
			echo "Insert Record"
			insertRecord
			;;
			
			3)
			echo "Update Record"
			updateRecord
			;;
			
			4)
			echo "Delete Record"
			deleteRecord
			;;
			
			5)
			echo "Search Record"
			searchRecord
			;;
			
			6)
			echo "View Address Book"
			viewAddressBook
			;;
			
			7)
			echo "Thankyou for using application"
			exit 1
			;;
		esac
	done
}


main






