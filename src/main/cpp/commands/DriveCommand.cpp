#include "commands/DriveCommand.h"
#include <subsystems/DriveSubsystem.h>
#include <iostream>
#include <frc2/command/Command.h>
#include <frc/Joystick.h>

DriveSubsystem drive;
double left,right;

DriveCommand::DriveCommand(DriveSubsystem* subystem, frc::Joystick* joystick) : m_drive(subystem), m_driverController(joystick) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drive);
  this->m_driverController = joystick;
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() {
  left = 0;
  right = 0;
}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
  left = m_driverController->GetRawAxis(1);
  right = m_driverController->GetRawAxis(5);

  drive.set(left,right);
}

// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {
  drive.stop();
}

// Returns true when the command should end.
bool DriveCommand::IsFinished() {
  return false;
}
