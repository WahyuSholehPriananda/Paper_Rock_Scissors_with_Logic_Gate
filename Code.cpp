#include <Arduino.h>
int skor1, skor2;
bool angka1 = LOW, angka2 = LOW, angka3 = LOW;
bool pass = true;

void tampilkan_skor(int player, int angka)
{
  if (angka == 0)
  {
    if (player == 1)
    {
      for (int i = 0; i < 4; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 2)
    {
      for (int i = 4; i < 8; i++)
        digitalWrite(i, LOW);
    }
  }
  else if (angka == 1)
  {
    if (player == 2)
    {
      digitalWrite(4, HIGH);
      for (int i = 5; i < 8; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(0, HIGH);
      for (int i = 1; i < 4; i++)
        digitalWrite(i, LOW);
    }
  }
  else if (angka == 2)
  {
    if (player == 2)
    {
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      for (int i = 6; i < 8; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(1, HIGH);
      digitalWrite(0, LOW);
      for (int i = 2; i < 4; i++)
        digitalWrite(i, LOW);
    }
  }
  else if (angka == 3)
  {
    if (player == 2)
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      for (int i = 6; i < 8; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      for (int i = 2; i < 4; i++)
        digitalWrite(i, LOW);
    }
  }
  else if (angka == 4)
  {
    if (player == 2)
    {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      for (int i = 4; i < 6; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      for (int i = 0; i < 2; i++)
        digitalWrite(i, LOW);
    }
  }
  else if (angka == 5)
  {
    if (player == 2)
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(0, HIGH);
      digitalWrite(1, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
    }
  }
  else if (angka == 6)
  {
    if (player == 2)
    {
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(1, HIGH);
      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
    }
  }
  else if (angka == 7)
  {
    if (player == 2)
    {
      digitalWrite(7, LOW);
      for (int i = 4; i < 7; i++)
        digitalWrite(i, HIGH);
    }
    else if (player == 1)
    {
      digitalWrite(3, LOW);
      for (int i = 0; i < 3; i++)
        digitalWrite(i, HIGH);
    }
  }
  else if (angka == 8)
  {
    if (player == 2)
    {
      digitalWrite(7, HIGH);
      for (int i = 4; i < 7; i++)
        digitalWrite(i, LOW);
    }
    else if (player == 1)
    {
      digitalWrite(3, HIGH);
      for (int i = 0; i < 3; i++)
        digitalWrite(i, LOW);
    }
  }
}

void setup()
{
  for (int i = 8; i < 11; i++)
    pinMode(i, INPUT);
  for (int i = 0; i < 8; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  if (angka2 == LOW && pass == true && angka1 == LOW && angka3 == LOW)
  {
    angka2 = digitalRead(9);
    angka1 = digitalRead(8);
    angka3 = digitalRead(10);
  }

  if (angka1 == HIGH)
  {
    skor1++;
    tampilkan_skor(1, skor1);
    angka1 = LOW;
    pass = false;
  }
  else if (angka2 == HIGH)
  {
    skor2++;
    tampilkan_skor(2, skor2);
    angka2 = LOW;
    pass = false;
  }
  else if (digitalRead(10) == HIGH)
  {
    tampilkan_skor(2, skor2);
    tampilkan_skor(1, skor1);
    angka3 = LOW;
    pass = false;
  }

  if (angka1 == LOW || angka2 == LOW || angka3 == LOW)
  {
    while (pass == false)
    {
      if (digitalRead(8) == LOW && digitalRead(9) == LOW && digitalRead(10) == LOW)
        pass = true;
      else if (digitalRead(8) == HIGH || digitalRead(9) == HIGH || digitalRead(10) == HIGH)
        pass = false;
    }
  }

  if (skor1 == 8)
    skor1 -= 8;
  else if (skor2 == 8)
    skor2 -= 8;
}
