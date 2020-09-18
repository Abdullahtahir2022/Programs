-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Aug 05, 2020 at 01:23 PM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.4.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `project`
--

-- --------------------------------------------------------

--
-- Table structure for table `account_details`
--

CREATE TABLE `account_details` (
  `id` int(11) NOT NULL,
  `role` int(11) DEFAULT NULL,
  `password` varchar(11) DEFAULT 'NULL'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `account_details`
--

INSERT INTO `account_details` (`id`, `role`, `password`) VALUES
(100, 1, '0'),
(200, 1, '0'),
(999, 1, '100'),
(1802016, 2, '123'),
(1802017, 2, '456');

-- --------------------------------------------------------

--
-- Table structure for table `assignment`
--

CREATE TABLE `assignment` (
  `id` int(11) NOT NULL,
  `teacher_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `assignment` varchar(50) NOT NULL,
  `date` date NOT NULL DEFAULT current_timestamp(),
  `Grades` varchar(5) DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `assignment`
--

INSERT INTO `assignment` (`id`, `teacher_id`, `course_id`, `student_id`, `assignment`, `date`, `Grades`) VALUES
(31, 100, 500, 1802016, 'PDF/hello.pdf', '2020-08-04', 'A'),
(32, 100, 200, 1802016, 'PDF/Report.pdf', '2020-08-04', 'F');

-- --------------------------------------------------------

--
-- Table structure for table `attendance`
--

CREATE TABLE `attendance` (
  `id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `teacher_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `date` date NOT NULL DEFAULT current_timestamp(),
  `status` varchar(10) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `attendance`
--

INSERT INTO `attendance` (`id`, `course_id`, `teacher_id`, `student_id`, `date`, `status`) VALUES
(138, 500, 100, 1802016, '2020-08-04', 'Present'),
(139, 200, 100, 1802016, '2020-08-04', 'Absent');

-- --------------------------------------------------------

--
-- Table structure for table `city`
--

CREATE TABLE `city` (
  `city_no` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `city`
--

INSERT INTO `city` (`city_no`, `name`) VALUES
(1, 'Lahore'),
(2, 'Peshawar'),
(3, 'Karachi'),
(4, 'Mianwali');

-- --------------------------------------------------------

--
-- Table structure for table `country`
--

CREATE TABLE `country` (
  `country_no` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `country`
--

INSERT INTO `country` (`country_no`, `name`) VALUES
(1, 'Pakistan'),
(2, 'Iran'),
(3, 'India'),
(4, 'Afghanistan');

-- --------------------------------------------------------

--
-- Table structure for table `course`
--

CREATE TABLE `course` (
  `course_id` int(11) NOT NULL,
  `course_name` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course`
--

INSERT INTO `course` (`course_id`, `course_name`) VALUES
(100, 'Calculus'),
(200, 'Chemistry'),
(300, 'Islamayat'),
(500, 'ITC');

-- --------------------------------------------------------

--
-- Table structure for table `course_student_enrolment`
--

CREATE TABLE `course_student_enrolment` (
  `no.` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `teacher_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course_student_enrolment`
--

INSERT INTO `course_student_enrolment` (`no.`, `student_id`, `course_id`, `teacher_id`) VALUES
(42, 1802016, 500, 100),
(43, 1802016, 200, 100),
(44, 1802017, 300, 200),
(45, 1802017, 100, 200);

-- --------------------------------------------------------

--
-- Table structure for table `course_teacher_enrolment`
--

CREATE TABLE `course_teacher_enrolment` (
  `no.` int(11) NOT NULL,
  `course_id` int(11) NOT NULL,
  `teacher_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `course_teacher_enrolment`
--

INSERT INTO `course_teacher_enrolment` (`no.`, `course_id`, `teacher_id`) VALUES
(24, 500, 100),
(25, 200, 100),
(26, 100, 200),
(27, 300, 200);

-- --------------------------------------------------------

--
-- Table structure for table `image`
--

CREATE TABLE `image` (
  `id` int(11) NOT NULL,
  `image` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `image`
--

INSERT INTO `image` (`id`, `image`) VALUES
(100, 'IMAGES/small.png'),
(200, 'IMAGES/personal-information.png'),
(1802016, 'IMAGES/personal-information.png'),
(1802017, 'IMAGES/personal-information.png');

-- --------------------------------------------------------

--
-- Table structure for table `role`
--

CREATE TABLE `role` (
  `role_id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `role`
--

INSERT INTO `role` (`role_id`, `name`) VALUES
(1, 'Teacher'),
(2, 'Student');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `student_id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL,
  `email` varchar(50) NOT NULL,
  `city_no` int(11) DEFAULT NULL,
  `country_no` int(11) DEFAULT NULL,
  `role` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`student_id`, `name`, `email`, `city_no`, `country_no`, `role`) VALUES
(1802016, 'Abdullah', 'abdullah2018@namal.edu.pk', 1, 1, 2),
(1802017, 'Haris', 'haris2018@namal.edu.pk', 4, 1, 2);

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE `teacher` (
  `teacher_id` int(11) NOT NULL,
  `name` varchar(30) NOT NULL,
  `email` varchar(30) NOT NULL,
  `city_no` int(11) NOT NULL,
  `country_no` int(11) NOT NULL,
  `role` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`teacher_id`, `name`, `email`, `city_no`, `country_no`, `role`) VALUES
(100, 'Sir Noman', 'noman@namal.edu.pk', 1, 1, 1),
(200, 'Sir Malik ', 'jahan@namal.edu.pk', 4, 1, 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `account_details`
--
ALTER TABLE `account_details`
  ADD PRIMARY KEY (`id`),
  ADD KEY `role` (`role`);

--
-- Indexes for table `assignment`
--
ALTER TABLE `assignment`
  ADD PRIMARY KEY (`id`),
  ADD KEY `course_id` (`course_id`),
  ADD KEY `student_id` (`student_id`),
  ADD KEY `teacher_id` (`teacher_id`);

--
-- Indexes for table `attendance`
--
ALTER TABLE `attendance`
  ADD PRIMARY KEY (`id`),
  ADD KEY `course_id` (`course_id`),
  ADD KEY `student_id` (`student_id`),
  ADD KEY `teacher_id` (`teacher_id`);

--
-- Indexes for table `city`
--
ALTER TABLE `city`
  ADD PRIMARY KEY (`city_no`);

--
-- Indexes for table `country`
--
ALTER TABLE `country`
  ADD PRIMARY KEY (`country_no`);

--
-- Indexes for table `course`
--
ALTER TABLE `course`
  ADD PRIMARY KEY (`course_id`);

--
-- Indexes for table `course_student_enrolment`
--
ALTER TABLE `course_student_enrolment`
  ADD PRIMARY KEY (`no.`),
  ADD KEY `student_id` (`student_id`),
  ADD KEY `course_id` (`course_id`),
  ADD KEY `teacher_id` (`teacher_id`);

--
-- Indexes for table `course_teacher_enrolment`
--
ALTER TABLE `course_teacher_enrolment`
  ADD PRIMARY KEY (`no.`),
  ADD KEY `course_id` (`course_id`),
  ADD KEY `teacher_id` (`teacher_id`);

--
-- Indexes for table `image`
--
ALTER TABLE `image`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`role_id`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`student_id`),
  ADD KEY `city_no` (`city_no`),
  ADD KEY `country_no` (`country_no`),
  ADD KEY `role` (`role`);

--
-- Indexes for table `teacher`
--
ALTER TABLE `teacher`
  ADD PRIMARY KEY (`teacher_id`),
  ADD KEY `country_no` (`country_no`),
  ADD KEY `city_no` (`city_no`),
  ADD KEY `role` (`role`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `assignment`
--
ALTER TABLE `assignment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=33;

--
-- AUTO_INCREMENT for table `attendance`
--
ALTER TABLE `attendance`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=140;

--
-- AUTO_INCREMENT for table `course_student_enrolment`
--
ALTER TABLE `course_student_enrolment`
  MODIFY `no.` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=46;

--
-- AUTO_INCREMENT for table `course_teacher_enrolment`
--
ALTER TABLE `course_teacher_enrolment`
  MODIFY `no.` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;

--
-- AUTO_INCREMENT for table `role`
--
ALTER TABLE `role`
  MODIFY `role_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `account_details`
--
ALTER TABLE `account_details`
  ADD CONSTRAINT `account_details_ibfk_1` FOREIGN KEY (`role`) REFERENCES `role` (`role_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `assignment`
--
ALTER TABLE `assignment`
  ADD CONSTRAINT `assignment_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `assignment_ibfk_2` FOREIGN KEY (`student_id`) REFERENCES `student` (`student_id`),
  ADD CONSTRAINT `assignment_ibfk_3` FOREIGN KEY (`teacher_id`) REFERENCES `teacher` (`teacher_id`);

--
-- Constraints for table `attendance`
--
ALTER TABLE `attendance`
  ADD CONSTRAINT `attendance_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `attendance_ibfk_2` FOREIGN KEY (`student_id`) REFERENCES `student` (`student_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `attendance_ibfk_3` FOREIGN KEY (`teacher_id`) REFERENCES `teacher` (`teacher_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `course_student_enrolment`
--
ALTER TABLE `course_student_enrolment`
  ADD CONSTRAINT `course_student_enrolment_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `student` (`student_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `course_student_enrolment_ibfk_2` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `course_student_enrolment_ibfk_3` FOREIGN KEY (`teacher_id`) REFERENCES `teacher` (`teacher_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `course_teacher_enrolment`
--
ALTER TABLE `course_teacher_enrolment`
  ADD CONSTRAINT `course_teacher_enrolment_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `course` (`course_id`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `course_teacher_enrolment_ibfk_2` FOREIGN KEY (`teacher_id`) REFERENCES `teacher` (`teacher_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `student`
--
ALTER TABLE `student`
  ADD CONSTRAINT `student_ibfk_2` FOREIGN KEY (`city_no`) REFERENCES `city` (`city_no`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `student_ibfk_3` FOREIGN KEY (`country_no`) REFERENCES `country` (`country_no`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `student_ibfk_4` FOREIGN KEY (`role`) REFERENCES `role` (`role_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `teacher`
--
ALTER TABLE `teacher`
  ADD CONSTRAINT `teacher_ibfk_1` FOREIGN KEY (`country_no`) REFERENCES `country` (`country_no`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `teacher_ibfk_2` FOREIGN KEY (`city_no`) REFERENCES `city` (`city_no`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `teacher_ibfk_3` FOREIGN KEY (`role`) REFERENCES `role` (`role_id`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
