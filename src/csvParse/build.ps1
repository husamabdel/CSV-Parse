Write-Output "Compiling csvParse....";

gcc csvParse.c charList.c -o csvParse

if($?){

    Write-Host "Compilation successful!" -ForegroundColor 'Green'
    exit 0;

} else {

    Write-Host "ERROR! There was an issue while compiling the code, you may need to install GCC in your system.." -ForegroundColor 'Red'

}