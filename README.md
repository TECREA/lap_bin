# lap_bin
## Binary files for CamKit

### Realizar en el camkit lo siguiente :
```
sudo apt install git
sudo git clone https://github.com/TECREA/lap_bin
```
set `sudo chmod +x installer.run` at `lap_bin/` <br>
after launch `sudo ./installer.run`

If copy file from windows SO :<br>
```
sudo apt install git
sudo git clone https://github.com/TECREA/lap_bin
```
Open WinSCP and copy-paste folder `lap_bin/` at `/home/pi/` if an error occurs while paste the file, then :  <br>
set `sudo chmod 777 /home/pi/`
set `sudo chmod +x installer.run` at `lap_bin/` <br>
If an error occurs while launching the file, then :  <br>
set `sudo awk '{ sub("\r$", ""); print }' installer.run > installer_new.run` at `lap_bin/` <br>
After set `sudo chmod +x installer_new.run` <br> 
After launch `sudo ./installer_new.run`
