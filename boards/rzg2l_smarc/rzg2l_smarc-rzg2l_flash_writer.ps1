# First of all check if Tera Term is installed, probably this is not the most elegant way but it works
$InstalledSoftware = Get-ChildItem "HKLM:\Software\Microsoft\Windows\CurrentVersion\Uninstall" 
$InstalledSoftware += Get-ChildItem "HKLM:\SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall\" 
foreach($obj in $InstalledSoftware){
	$InstalledSoftwareFiltered += $obj.GetValue('DisplayName') + "/" + $obj.GetValue('InstallLocation') + "`n"
}
$InstalledSoftwareFiltered = $InstalledSoftwareFiltered -split "`n"

$TeraTerm = $InstalledSoftwareFiltered | Select-String -Pattern 'Tera Term'

if ($TeraTerm.Length -eq 0) {
	Write-Host "Tera Term is not installed"
	exit
}
else {
	# Get install path
	$TeraTermInstallPath = ($TeraTerm -split "/")[1]
	$TeraTerm = ($TeraTerm -split "/")[0]
	write-host $TeraTerm
	write-host $TeraTermInstallPath
}

# Create environment and poipulate it by downloading resources from GitHub
$Folder1="program_rzg2l_bootloaders"
$Folder2="Binaries"
$MotFile="Flash_Writer_SCIF_RZG2L_SMARC_DDR4_2GB.mot"
$MacroFile="rzg2l_smarc-rzg2l_flash_writer.ttl"
$GitHubURI1="https://raw.githubusercontent.com/seebe/rzg_stuff/master/boards/rzg2l_smarc/"
$GitHubURI2="https://github.com/seebe/rzg_stuff/raw/master/boards/rzg2l_smarc/Binaries/"
$BL2="bl2_bp-smarc-rzg2l.bin"
$fip="fip-smarc-rzg2l.bin"

if (!(Test-Path -Path $Folder1)) {
    md $Folder1
}
 
Push-Location $Folder1
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12

if (!(Test-Path -Path $MotFile)) {
	wget "$GitHubURI1$MotFile" -outfile "$MotFile"
}

if (!(Test-Path -Path $MacroFile)) {
	wget "$GitHubURI1$MacroFile" -outfile "$MacroFile"
}

# Use [System.IO.Ports.SerialPort] to get a list of available COMs
$COMs=[System.IO.Ports.SerialPort]::getportnames() 
Write-Host "$COMs"

if ($COMs.Length -gt 0) {
	# First detected COM is the default one
	$default_COM=$COMs[0].Substring(3,1)
}
else {
	Write-Host "No COM ports available"
	Pop-Location
	exit
}

# Ask user intervention to confirm COM port
[void][Reflection.Assembly]::LoadWithPartialName('Microsoft.VisualBasic')
$title = 'COM port choice'
$msg   = "Please enter COM port, using the number only.`r`nE.g. to select COM4 enter 4`n`r`n`rAvailable COM ports:`r`n`r`n$COMs"
$chosen_COM = [Microsoft.VisualBasic.Interaction]::InputBox($msg, $title, $default_COM)


# Download binaries to be programmed from GitHub
if (!(Test-Path -Path $Folder2)) {
    md $Folder2
}
Push-Location $Folder2
if (!(Test-Path -Path $BL2)) {
	wget "$GitHubURI2$BL2" -outfile "$BL2"
}
if (!(Test-Path -Path $fip)) {
	wget "$GitHubURI2$fip" -outfile "$fip"
}
Pop-Location

# Create a Windows shortcut to launch Tera Term MacroFile
$shell = New-Object -ComObject WScript.Shell
$path=Get-Location
$shortcut = $shell.CreateShortcut("$path\link.lnk")
$shortcut.TargetPath = "$TeraTermInstallPath" + "ttpmacro.exe"
$shortcut.Arguments = "$path\$MacroFile $chosen_COM"
$shortcut.Save()

# Launch MacroFile
Invoke-Item -Path "$path\link.lnk"

Write-Host "Done!"

Pop-Location