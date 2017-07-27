#load bus 
#
ogg123 -q /root/Music/gamelan_bebarongan_calonarang.ogg &

eval `dbus-launch` 
export DBUS_SESSION_BUS_ADDRESS

# Load Colors & Pulse 
pulseaudio -D &
sleep 2
start-pulseaudio-x11 &
xrdb -merge ~/.Xresources 

# Load Wallpaper
sh ~/.fehbg &

# Load bitmap fonts
xset +fp /root/.fonts/ 
xset fp rehash 
sleep 2

# dwmstatus + exec dwm
dwmstatus &
exec dwm  
