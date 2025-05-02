Instalar Docker.  
Clona el firmware oficial del Flipper:  
'''git clone https://github.com/flipperdevices/flipperzero-firmware.git  
cd flipperzero-firmware  
./fbt fap_apk create'''  

Dentro de applications_user, crea una nueva carpeta:  
'''mkdir -p applications_user/ir_rf_bridge'''  

Compilar:  
'''./fbt fap_ir_rf_bridge  
./fbt install_fap_ir_rf_bridge'''
