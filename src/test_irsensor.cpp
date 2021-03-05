//Meine Sensor Bennenung: [Left][HalfLeft][LeftFromMiddle][MiddleLeft][MiddleRight][RightFromMiddle][HalfRight][Right]
//ich gehe davon aus dass der normale Speed beim geradeausfahren 200 ist
if ((LeftFromMiddle =0) & (RightFromMiddle =1))
{
    analogWrite(LeftMotor, 200);
    analogWrite(RightMotor, 190)
};
if ((LeftFromMiddle =1) & (RightFromMiddle =0))
{
    analogWrite(LeftMotor, 190)
    analogWrite(RightMotor, 200)
};
if ((HalfLeft =0) & (HalfRight =1))
{
    analogWrite(LeftMotor, 200);
    analogWrite(RightMotor, 180)
};
if ((HalfLeft =1) & (HalfRight =0))
{
    analogWrite(LeftMotor, 180);
    analogWrite(RightMotor, 200)
};
if ((Left =0) & (Right =1))
{
    analogWrite(LeftMotor, 200);
    analogWrite(RightMotor, 170)
};
if ((Left =1) & (Right =0))
{
    analogWrite(LeftMotor, 170);
    analogWrite(RightMotor, 200)
}