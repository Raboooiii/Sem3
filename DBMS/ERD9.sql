-- MySQL Script generated by MySQL Workbench
-- Thu Oct 17 15:43:01 2024
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Courses`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Courses` (
  `C_Number` INT NOT NULL,
  `Title` VARCHAR(45) NULL,
  `Credits` INT NULL,
  `Syllabus` VARCHAR(45) NULL,
  `Prerequisites` VARCHAR(45) NULL,
  PRIMARY KEY (`C_Number`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Courses_Offerings`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Courses_Offerings` (
  `C_Number` INT NOT NULL,
  `Year` INT NULL,
  `Semester` INT NULL,
  `Section_Number` INT NULL,
  `Timings` TIME NULL,
  `Classroom` VARCHAR(10) NULL,
  `Instructor` VARCHAR(20) NULL,
  PRIMARY KEY (`C_Number`, `Section_Number`),
  CONSTRAINT `C_Number`
    FOREIGN KEY (`C_Number`)
    REFERENCES `mydb`.`Courses` (`C_Number`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Student`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Student` (
  `Name` VARCHAR(20) NULL,
  `SID` INT NOT NULL,
  `Program` VARCHAR(45) NULL,
  PRIMARY KEY (`SID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Instructor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Instructor` (
  `Name` VARCHAR(20) NULL,
  `Instructor_ID` INT NOT NULL,
  `Title` VARCHAR(45) NULL,
  `Department` VARCHAR(45) NULL,
  PRIMARY KEY (`Instructor_ID`),
  CONSTRAINT `Title`
    FOREIGN KEY ()
    REFERENCES `mydb`.`Courses` ()
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`ScoreCard`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`ScoreCard` (
  `SID` INT NOT NULL,
  `C_Number` INT NOT NULL,
  CONSTRAINT `SID`
    FOREIGN KEY (`SID` , `C_Number`)
    REFERENCES `mydb`.`Student` (`SID` , `SID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `C_Number`
    FOREIGN KEY (`SID` , `C_Number`)
    REFERENCES `mydb`.`Courses` (`C_Number` , `C_Number`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;