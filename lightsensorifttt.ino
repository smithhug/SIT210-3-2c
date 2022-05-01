int lightsensor = A0;
int lightval;
bool sun = false;

void setup() {
    Serial.begin(9600);
}

void loop() {
    lightval = analogRead(lightsensor);
    if (lightval > 100){
        if (sun == false)
            Particle.publish("l-sensor", "on");
        sun = true;
    } else {
        if (sun == true)
            Particle.publish("l-sensor", "off");
        sun = false;
    }

    delay(1000);

}