#include <HTTPClient.h>
#include <WiFi.h>

const char* ssid = "Totalplay-87A5";
const char* password = "87A58C51nGUEnffq";
int A = 0;
int B = 0;

void setup() {
  delay(10);
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { // Check for the connection
    delay(500);
    Serial.print(".");
  }

  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Incrementar los valores de A y B
  A++;
  B++;

  if(WiFi.status() == WL_CONNECTED) { // Check WiFi connection status
    HTTPClient http;
    String datos_a_enviar = "A=" + String(A) + "&B=" + String(B);

    http.begin("https://practica5redes.000webhostapp.com/"); // Indicamos el destino
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int codigo_respuesta = http.POST(datos_a_enviar);

    if(codigo_respuesta == 200) {
      Serial.println("Datos enviados correctamente");
    } else {
      Serial.print("Error enviando POST, código: ");
      Serial.println(codigo_respuesta);
    }

    http.end(); // Libero recursos
  } else {
    Serial.println("Error en la conexión WIFI");
  }

  delay(2000);
}
