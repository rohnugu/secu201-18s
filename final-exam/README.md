# Final Exam, SECU201-18S
SECU201 Data Structure, Spring 2018

Errata
 - In Problem 7, "Problem 8" should be changed to "Problem 6".

How to submit your work
 - Clone our SECU201 GitHub repository in your computer.
 - Archive your whole work in a ZIP file in other directory.
   * The filename should be SECU201-18S_final-exam_201727####.zip
 - Copy the ZIP file to ./final-exam directory.
 - Using the public key ./final-exam/publickey.asc, encrypt the ZIP, and the resulting filename should be SECU201-18S_final-exam_201727####.zip.asc.
   * In Windows: Import the public key, and encrypt the ZIP file.
     * For More Information: http://newsreading.tistory.com/77?category=563856
   * In Linux: Import the public key with gpg --import publickey.asc, and encrypt the ZIP file with gpg -e -r hjroh@korea.ac.kr SECU201-18S_final-exam_201727####.zip.
     * For More Information: https://linuxaria.com/howto/how-to-easily-encrypt-a-file-with-gpg-on-linux
  * Remove the ZIP file (but definitly backup the file!) and commit the encrypted asc file to your local git repository.
  * Push the commit to the global GitHub repository. Verify your submission is successfully uploaded.
