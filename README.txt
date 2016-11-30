Assignment 2, CPSC-456, Fall 2016

Group Members
    - Marjan Farhad    		marzrocks@csu.fullerton.edu   
    - Neenu  Varghese   	neenu.varghese@csu.fullerton.edu
    - Ashish Merani			ashishmerani@csu.fullerton.edu
    - Anusha Devabhaktuni	toanushad@csu.fullerton.edu

Part 1-
	
	1. Try opening the file using the 7-zip program. What happens? (Note: one way to open  the file using the 7-zip program is to right-click on result.7z and choose 7-zip → Open archive. What happens? Are you able to extract and run the worm.bat file inside the archive?
	
		When we run the command 
			copy /B fireworks.gif + worm.7z result
	
		A result file was generated. Later, we renamed the file as result.7z and opened the file using the 7-zip -> Open archive -> 7z. 
	
		Then the worm.bat file is presented. We could not run the worm.bat file inside the archive and the error states that Windows cannot find the c:\Users\Mike\worm.bat
	
		No, the file wouldn’t extract or run. An error message was displayed from 7zip that the file couldn’t be opened as an archive.

	2. Repeat the above steps, but this time rename the file to result.gif extension. Try opening the file. What happens?
	
		When we renamed the result file with .gif extension, the file opens up as a replica of the original .gif file that we downloaded from the internet, showing the original image. The image opens up in its default picture viewer.

	3. Explain what is happening. Do some research in order to find out what the above copy command does. In your explanation be sure to explain the role of each argument in the above command. Also, be sure to explain how Windows handles files which leads to the above behavior. Include the answers to these questions in the README file you submit.
	
		When we run the command:             
			copy /B fireworks.gif + worm.7z result
		A result file was generated. Later, we renamed the file as result.7z and opened the file using the 7-zip -> Open archive -> 7z. Then the worm.bat file is presented. We could not run the worm.bat file inside the archive and the error states that Windows cannot find the c:\Users\Mike\worm.bat
	
		When we run the command again:         
			copy /B fireworks.gif + worm.7z result
	
		The same result file was generated, but we renamed the file as result.gif instead and the file is opened using any image viewer. 
	
			copy [/b] <source1> + <source2>  <destination> 
	
		The copy command in Windows command line copies one or more files from one location to another. /b: Indicates a binary file. The copy /b command treats the source files as binary files and copies them byte by byte to destination file. Also, the effect of /b is dependent on its position in the command line prompt. For instance, if we write copy /b <source> + <source> <destination>, copy copies the entire file, including any end-of-file character, however if we write copy <source> + <source> /b <destination>, copy does not copy the end-file character. Since, we are specifying two files as our sources with + symbol in the middle, copy combines both files into a single file with the filename we specified in destination so in our case our files, fireworks.gif and worm.7z, were combined with the name results.gif. 
	
		Since Windows handles opening files by observing their specified extension, the newly merged file opens with the program that’s been assigned to the extension so in our case the resulted file will open up with a program that handles .gif extensions. For example, if the file has a .gif or .jpg extension it will open the file with an image viewer. If the file has .doc or .docx extension it will open up the file with microsoft word or any word processor program.

		Sources: https://technet.microsoft.com/en-us/library/bb490886.aspx,
		https://superuser.com/questions/453245/what-exactly-happens-when-you-use-the-copy-b-command

	4. How can this technique be used for hiding malicious codes?
	
		This technique can be used for hiding malicious codes because we are basically doing the steps of creating a binder, which is merging one or more executables, but in this case we are combining a .gif image with a worm.bat file. When we open the result file we created (result.gif), it opens up as a normal .gif extension, but it contains extra bytes belonging to the zip file, which contains the malicious code (worm.bat). 

		This technique can be used to hide malicious code, because we can merge a legitimate executable, or file with malicious code. If an unsuspecting person downloads the merged file from a file sharing website, they will automatically assume it’s safe then they will download and open up the file possibly infecting their computer. 

	5. How robust is this technique in terms of avoiding detection by anti-virus tools? You may need to do some research.
	
		This method is not very robust when trying to avoid being detected by anti-malware software since the software can scan for malicious code based on its signature, which is a binary pattern of known malware. Also, our malicious code isn’t encrypted because we copied the malicious code and the .gif image in binary mode without any encryption methods, which makes it easier for the anti-malware software to find its signature and compare it to their databases of malware signatures. 
	
		Sources: http://www.securityweek.com/brazilian-trojan-conceals-malicious-code-png-image 
		http://searchsecurity.techtarget.com/tip/How-antivirus-software-works-Virus-detection-techniques
		https://stackoverflow.com/questions/1396443/how-do-antivirus-programs-detect-viruses

Instructions for Part 2: 

Extra Credit: Yes we have implemented extra credit

Instructions for Extra Credit: 
