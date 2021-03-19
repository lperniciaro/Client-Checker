# Client-Checker Download

Windows: https://github.com/lperniciaro/Client-Checker/archive/main.zip

If you have any problems running the .exe make sure you have the latest version of Visual C++ Redestributable installed (not 100% sure on this I got the program to run on different machines but not sure what dependency is required just lmk if you have issues)

MacOS: no

Linux: Ask me if you want it

# About

The Client Checker takes data from Atera, SentinelOne, and Screenconnect and compiles it all in one place. The completed CSV file will consolidate the information from their respective places, and let the user know which pieces of software are missing from each individual machine. It will also provide handy information on machines. In order to do this, you must gather the input files.

# Gathering the Files

# Atera

Atera makes it easy:

•	Reports > Auditor > Select Customer > Export to Excel

Open the xls file in Excel, then:

•	File > Export > Change File Type > Export as CSV 

Save the CSV file in the same directory as the System Checker.

I usually chose a name like "AteraConnally.csv"

# Connectwise

This one is a little more involved as screenconnect doesn't have an easy way to generate a report (for now). A comma separated list of usernames must be created for screenconnect.
1.	Select a client
2.	Check all computers
3.	In the top right corner, triple click the list of usernames
4.	Paste the list into a text file in the directory as the System Checker (make sure there isn’t an endline at the end or itll mess up the end of the sheet)
Ex. "ConnectwiseConnally.txt"

# SentinelOne

EZPZ with this one
1.  Go to Sentinels
2.  In the top right, click export. SentinelOne will download a CSV file with all the correct information
3.  Rename endpoints.csv file to something relevant Ex. "SentinelConnally.csv"

# How to Use

Yay! Hopefully you have all the input files you need and you can actually get some work done.

Upon launching the Client Checker, you will be greeted with choices for which files you would like to load. 

![console image](https://i.imgur.com/wYohLPX.png)

Select a choice by entering the number listed before the prompt. IE, if I wanted to load an atera file, type 2 then press enter.

After you will be prompted for the file name, type it in exactly how you named it when gathering the input data. Don't forget to add the extension as well.
So, if I wanted to load the Connally Atera file, type "AteraConnally.csv" (or whatever you decided to name it)

For screenconnect "filename.txt".

Once you have loaded in files for Connectwise, Atera, and SentinelOne press 6 to output the file. You will be prompted for an output file name. Obviously the name doesn't matter, just make sure to add ".csv" at the end. You should see the filename in the directory of the ClientChecker and you're done! You should also see a preliminary output of Ys and Ns. If you see an entire row of N you probably input the data incorrectly or a file was not able to be read.

Once you open the final csv file, open it and format it as a table and you're good to go. You can now upload the document to OneDrive.

I also like to use conditional formatting in excel to highlight values labeled "N" as red. To do this, highlight the columns, select coniditional formatting > highlight cell rules > equal to and type the letter N. 

There will be a duplicate entry if a machine on Connectwise has been renamed to something other than the exact machine name. You will notice this as most likely the names are similar. If there is a machine that has Atera and AntiVirus, but no screenconnect, try to find a matching machine that states only ConnectWise is installed. It will most likely have a similar name and be easy to decipher.

# Extra notes

There are choices for Symantec and Sophos, those are WIP and don't do anything in the latest version right now.

Errors do happen, usually its only on one machine if there's some weird edge case for the data. If something catastrophically bad happens let me know.

# Things to Do

Get the code signed so the program does not appear as malicious to every single antivirus software.

Either delete Symantec and Sophos options, or get them working again. I'll have to see if we still use either of those softwares for any of our clients.

# Changelog
v1.01: 

•	Fixed restart bug, you no longer have to restart the program to work on multiple sites

•	Prints version number when initially launching application
