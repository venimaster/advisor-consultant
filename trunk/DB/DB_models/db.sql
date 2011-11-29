
CREATE TABLE answer_variant_list
(
	a_v_id               TINYINT NOT NULL,
	answer_variant_1     TEXT NOT NULL,
	answer_variant_2     TEXT NOT NULL,
	answer_variant_3     TEXT NOT NULL,
	answer_variant_4     TEXT NOT NULL,
	answer_variant_5     TEXT NOT NULL,
	answer_variant_6     TEXT NOT NULL,
	answer_variant_7     TEXT NOT NULL,
	answer_variant_8     TEXT NOT NULL,
	answer_variant_9     TEXT NOT NULL,
	answer_variant_10    TEXT NOT NULL,
	answer_variant_11    TEXT NOT NULL
);



ALTER TABLE answer_variant_list
ADD PRIMARY KEY (a_v_id);



CREATE TABLE c_s_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE c_s_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE creator_speculator
(
	id                   TINYINT NOT NULL,
	question             TEXT NOT NULL,
	hemisphere           CHAR(1) NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE creator_speculator
ADD PRIMARY KEY (id);



CREATE TABLE equivalents
(
	id                   TINYINT NOT NULL,
	equivalent           TINYINT NOT NULL
);



ALTER TABLE equivalents
ADD PRIMARY KEY (id,equivalent);



CREATE TABLE f_f_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE f_f_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE fielddependence_fieldindependence
(
	id                   TINYINT NOT NULL,
	right_answer         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE fielddependence_fieldindependence
ADD PRIMARY KEY (id);



CREATE TABLE glossary
(
	id                   TINYINT NOT NULL,
	termin               TEXT NOT NULL,
	abbreviation         TEXT NULL,
	definition           TEXT NULL
);



ALTER TABLE glossary
ADD PRIMARY KEY (id);



CREATE TABLE i_e_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE i_e_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE i_k_i_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE i_k_i_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE ideal_expert
(
	id                   TINYINT NOT NULL,
	question             TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE ideal_expert
ADD PRIMARY KEY (id);



CREATE TABLE ideal_knowledge_ingeneer
(
	id                   TINYINT NOT NULL,
	question             TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE ideal_knowledge_ingeneer
ADD PRIMARY KEY (id);



CREATE TABLE integ_m_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE integ_m_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE integration_means
(
	id                   TINYINT NOT NULL,
	integration_mean     TEXT NOT NULL
);



ALTER TABLE integration_means
ADD PRIMARY KEY (id);



CREATE TABLE inter_m_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE inter_m_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE interface_means
(
	id                   TINYINT NOT NULL,
	interface_mean       TEXT NOT NULL
);



ALTER TABLE interface_means
ADD PRIMARY KEY (id);



CREATE TABLE k_r_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE k_r_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE knowledge_representation
(
	id                   TINYINT NOT NULL,
	knowledge_representation TEXT NOT NULL
);



ALTER TABLE knowledge_representation
ADD PRIMARY KEY (id);



CREATE TABLE m_c_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE m_c_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE manufacturing_company
(
	id                   TINYINT NOT NULL,
	company              TEXT NOT NULL
);



ALTER TABLE manufacturing_company
ADD PRIMARY KEY (id);



CREATE TABLE o_r_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE o_r_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE opportunity_research
(
	id                   TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE opportunity_research
ADD PRIMARY KEY (id);



CREATE TABLE p_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE p_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE p_c_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE p_c_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE p_r_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE p_r_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE platform
(
	id                   TINYINT NOT NULL,
	platform_name        TEXT NOT NULL
);



ALTER TABLE platform
ADD PRIMARY KEY (id);



CREATE TABLE producing_country
(
	id                   TINYINT NOT NULL,
	country              TEXT NOT NULL
);



ALTER TABLE producing_country
ADD PRIMARY KEY (id);



CREATE TABLE programming_language
(
	id                   TINYINT NOT NULL,
	language             TEXT NOT NULL
);



ALTER TABLE programming_language
ADD PRIMARY KEY (id);



CREATE TABLE project
(
	id                   TINYINT NOT NULL,
	project_name         TEXT NOT NULL
);



ALTER TABLE project
ADD PRIMARY KEY (id);



CREATE TABLE project_group
(
	u_id                 TINYINT NOT NULL,
	pr_id                TINYINT NOT NULL
);



ALTER TABLE project_group
ADD PRIMARY KEY (u_id,pr_id);



CREATE TABLE propriety_research
(
	id                   TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE propriety_research
ADD PRIMARY KEY (id);



CREATE TABLE r_l_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE r_l_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE r_r_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE r_r_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE r_v_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE r_v_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE references_
(
	id                   TINYINT NOT NULL,
	reference            TEXT NOT NULL
);



ALTER TABLE references_
ADD PRIMARY KEY (id);



CREATE TABLE relevance_research
(
	id                   TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE relevance_research
ADD PRIMARY KEY (id);



CREATE TABLE rigidity_versatility
(
	id                   TINYINT NOT NULL,
	statement            TEXT NOT NULL,
	right_answer         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE rigidity_versatility
ADD PRIMARY KEY (id);



CREATE TABLE s_l_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE s_l_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE sol_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE sol_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE solver
(
	id                   TINYINT NOT NULL,
	solver               TEXT NOT NULL
);



ALTER TABLE solver
ADD PRIMARY KEY (id);



CREATE TABLE sys_answer
(
	answer               TEXT NOT NULL,
	id                   TINYINT NOT NULL,
	u_id                 TINYINT NOT NULL
);



ALTER TABLE sys_answer
ADD PRIMARY KEY (id,u_id);



CREATE TABLE system
(
	id                   TINYINT NOT NULL,
	system_name          TEXT NOT NULL
);



ALTER TABLE system
ADD PRIMARY KEY (id);



CREATE TABLE system_integration_means
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_integration_means
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_interface_means
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_interface_means
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_knowledge_representation
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_knowledge_representation
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_manufacturing_company
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_manufacturing_company
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_platform
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_platform
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_producing_country
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_producing_country
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_realization_language
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_realization_language
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_solver
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_solver
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE system_supported_language
(
	id                   TINYINT NOT NULL,
	sy_id                TINYINT NOT NULL
);



ALTER TABLE system_supported_language
ADD PRIMARY KEY (id,sy_id);



CREATE TABLE t_t_answer
(
	answer               TEXT NOT NULL,
	u_id                 TINYINT NOT NULL,
	id                   TINYINT NOT NULL
);



ALTER TABLE t_t_answer
ADD PRIMARY KEY (u_id,id);



CREATE TABLE temperament_type
(
	id                   TINYINT NOT NULL,
	question             TEXT NOT NULL,
	sincerity            TEXT NOT NULL,
	instability          TEXT NOT NULL,
	extraversion         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE temperament_type
ADD PRIMARY KEY (id);



CREATE TABLE user
(
	u_id                 TINYINT NOT NULL,
	password             TEXT NOT NULL,
	name                 TEXT NOT NULL,
	gender               ENUM('муж','жен') NULL,
	age                  tinyint NULL,
	u_g_id               TINYINT NOT NULL,
	login                TEXT NOT NULL
);



ALTER TABLE user
ADD PRIMARY KEY (u_id);



CREATE TABLE user_group
(
	id                   TINYINT NOT NULL,
	group_name           TEXT NOT NULL
);



ALTER TABLE user_group
ADD PRIMARY KEY (id);



ALTER TABLE c_s_answer
ADD FOREIGN KEY R_4 (u_id) REFERENCES user (u_id);



ALTER TABLE c_s_answer
ADD FOREIGN KEY R_6 (id) REFERENCES creator_speculator (id);



ALTER TABLE creator_speculator
ADD FOREIGN KEY R_3 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE equivalents
ADD FOREIGN KEY R_140 (id) REFERENCES glossary (id);



ALTER TABLE equivalents
ADD FOREIGN KEY R_143 (equivalent) REFERENCES glossary (id);



ALTER TABLE f_f_answer
ADD FOREIGN KEY R_15 (id) REFERENCES fielddependence_fieldindependence (id);



ALTER TABLE f_f_answer
ADD FOREIGN KEY R_16 (u_id) REFERENCES user (u_id);



ALTER TABLE fielddependence_fieldindependence
ADD FOREIGN KEY R_9 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE i_e_answer
ADD FOREIGN KEY R_28 (id) REFERENCES ideal_expert (id);



ALTER TABLE i_e_answer
ADD FOREIGN KEY R_29 (u_id) REFERENCES user (u_id);



ALTER TABLE i_k_i_answer
ADD FOREIGN KEY R_27 (id) REFERENCES ideal_knowledge_ingeneer (id);



ALTER TABLE i_k_i_answer
ADD FOREIGN KEY R_30 (u_id) REFERENCES user (u_id);



ALTER TABLE ideal_expert
ADD FOREIGN KEY R_8 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE ideal_knowledge_ingeneer
ADD FOREIGN KEY R_7 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE integ_m_answer
ADD FOREIGN KEY R_64 (id) REFERENCES integration_means (id);



ALTER TABLE integ_m_answer
ADD FOREIGN KEY R_65 (u_id) REFERENCES user (u_id);



ALTER TABLE inter_m_answer
ADD FOREIGN KEY R_66 (id) REFERENCES interface_means (id);



ALTER TABLE inter_m_answer
ADD FOREIGN KEY R_67 (u_id) REFERENCES user (u_id);



ALTER TABLE k_r_answer
ADD FOREIGN KEY R_68 (id) REFERENCES knowledge_representation (id);



ALTER TABLE k_r_answer
ADD FOREIGN KEY R_69 (u_id) REFERENCES user (u_id);



ALTER TABLE m_c_answer
ADD FOREIGN KEY R_56 (u_id) REFERENCES user (u_id);



ALTER TABLE m_c_answer
ADD FOREIGN KEY R_57 (id) REFERENCES manufacturing_company (id);



ALTER TABLE o_r_answer
ADD FOREIGN KEY R_21 (u_id) REFERENCES user (u_id);



ALTER TABLE o_r_answer
ADD FOREIGN KEY R_26 (id) REFERENCES opportunity_research (id);



ALTER TABLE opportunity_research
ADD FOREIGN KEY R_10 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE p_answer
ADD FOREIGN KEY R_58 (u_id) REFERENCES user (u_id);



ALTER TABLE p_answer
ADD FOREIGN KEY R_59 (id) REFERENCES platform (id);



ALTER TABLE p_c_answer
ADD FOREIGN KEY R_54 (id) REFERENCES producing_country (id);



ALTER TABLE p_c_answer
ADD FOREIGN KEY R_55 (u_id) REFERENCES user (u_id);



ALTER TABLE p_r_answer
ADD FOREIGN KEY R_22 (u_id) REFERENCES user (u_id);



ALTER TABLE p_r_answer
ADD FOREIGN KEY R_25 (id) REFERENCES propriety_research (id);



ALTER TABLE project_group
ADD FOREIGN KEY R_74 (u_id) REFERENCES user (u_id);



ALTER TABLE project_group
ADD FOREIGN KEY R_73 (pr_id) REFERENCES project (id);



ALTER TABLE propriety_research
ADD FOREIGN KEY R_12 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE r_l_answer
ADD FOREIGN KEY R_60 (u_id) REFERENCES user (u_id);



ALTER TABLE r_l_answer
ADD FOREIGN KEY R_61 (id) REFERENCES programming_language (id);



ALTER TABLE r_r_answer
ADD FOREIGN KEY R_23 (u_id) REFERENCES user (u_id);



ALTER TABLE r_r_answer
ADD FOREIGN KEY R_24 (id) REFERENCES relevance_research (id);



ALTER TABLE r_v_answer
ADD FOREIGN KEY R_17 (u_id) REFERENCES user (u_id);



ALTER TABLE r_v_answer
ADD FOREIGN KEY R_19 (id) REFERENCES rigidity_versatility (id);



ALTER TABLE relevance_research
ADD FOREIGN KEY R_11 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE rigidity_versatility
ADD FOREIGN KEY R_14 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE s_l_answer
ADD FOREIGN KEY R_62 (u_id) REFERENCES user (u_id);



ALTER TABLE s_l_answer
ADD FOREIGN KEY R_63 (id) REFERENCES programming_language (id);



ALTER TABLE sol_answer
ADD FOREIGN KEY R_70 (id) REFERENCES solver (id);



ALTER TABLE sol_answer
ADD FOREIGN KEY R_71 (u_id) REFERENCES user (u_id);



ALTER TABLE sys_answer
ADD FOREIGN KEY R_52 (id) REFERENCES system (id);



ALTER TABLE sys_answer
ADD FOREIGN KEY R_53 (u_id) REFERENCES user (u_id);



ALTER TABLE system_integration_means
ADD FOREIGN KEY R_37 (id) REFERENCES integration_means (id);



ALTER TABLE system_integration_means
ADD FOREIGN KEY R_38 (sy_id) REFERENCES system (id);



ALTER TABLE system_interface_means
ADD FOREIGN KEY R_39 (sy_id) REFERENCES system (id);



ALTER TABLE system_interface_means
ADD FOREIGN KEY R_40 (id) REFERENCES interface_means (id);



ALTER TABLE system_knowledge_representation
ADD FOREIGN KEY R_32 (sy_id) REFERENCES system (id);



ALTER TABLE system_knowledge_representation
ADD FOREIGN KEY R_33 (id) REFERENCES knowledge_representation (id);



ALTER TABLE system_manufacturing_company
ADD FOREIGN KEY R_41 (id) REFERENCES manufacturing_company (id);



ALTER TABLE system_manufacturing_company
ADD FOREIGN KEY R_42 (sy_id) REFERENCES system (id);



ALTER TABLE system_platform
ADD FOREIGN KEY R_43 (id) REFERENCES platform (id);



ALTER TABLE system_platform
ADD FOREIGN KEY R_45 (sy_id) REFERENCES system (id);



ALTER TABLE system_producing_country
ADD FOREIGN KEY R_46 (id) REFERENCES producing_country (id);



ALTER TABLE system_producing_country
ADD FOREIGN KEY R_47 (sy_id) REFERENCES system (id);



ALTER TABLE system_realization_language
ADD FOREIGN KEY R_48 (id) REFERENCES programming_language (id);



ALTER TABLE system_realization_language
ADD FOREIGN KEY R_49 (sy_id) REFERENCES system (id);



ALTER TABLE system_solver
ADD FOREIGN KEY R_34 (sy_id) REFERENCES system (id);



ALTER TABLE system_solver
ADD FOREIGN KEY R_35 (id) REFERENCES solver (id);



ALTER TABLE system_supported_language
ADD FOREIGN KEY R_50 (id) REFERENCES programming_language (id);



ALTER TABLE system_supported_language
ADD FOREIGN KEY R_51 (sy_id) REFERENCES system (id);



ALTER TABLE t_t_answer
ADD FOREIGN KEY R_18 (u_id) REFERENCES user (u_id);



ALTER TABLE t_t_answer
ADD FOREIGN KEY R_20 (id) REFERENCES temperament_type (id);



ALTER TABLE temperament_type
ADD FOREIGN KEY R_13 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE user
ADD FOREIGN KEY R_72 (u_g_id) REFERENCES user_group (id);


