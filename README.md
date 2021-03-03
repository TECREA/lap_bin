# lap_bin
## Binary files for CamKit

### Realizar en el camkit lo siguiente :
```
sudo apt install git
sudo git clone https://github.com/TECREA/lap_bin
```
set `sudo chmod +x install.run` at `lap_bin/` <br>
after launch `./installer.run`

if copy file from windows SO :
set `sudo awk '{ sub("\r$", ""); print }' installer.run > installer_new.run` at `lap_bin/` <br>
set `sudo chmod +x installer_new.run` <br> 
after launch `./installer_new.run`
