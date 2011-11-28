
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
	login                VARCHAR(30) NOT NULL,
	c_s_id               TINYINT NOT NULL
);



ALTER TABLE c_s_answer
ADD PRIMARY KEY (login,c_s_id);



CREATE TABLE creator_speculator
(
	c_s_id               TINYINT NOT NULL,
	question             TEXT NOT NULL,
	hemisphere           CHAR(1) NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE creator_speculator
ADD PRIMARY KEY (c_s_id);



CREATE TABLE f_f_answer
(
	answer               TEXT NOT NULL,
	f_f_id               TINYINT NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE f_f_answer
ADD PRIMARY KEY (f_f_id,login);



CREATE TABLE fielddependence_fieldindependence
(
	f_f_id               TINYINT NOT NULL,
	right_answer         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE fielddependence_fieldindependence
ADD PRIMARY KEY (f_f_id);



CREATE TABLE glossary
(
	g_id                 TINYINT NOT NULL,
	termin               TEXT NOT NULL,
	abbreviation         TEXT NOT NULL,
	definition           TEXT NOT NULL
);



ALTER TABLE glossary
ADD PRIMARY KEY (g_id);



CREATE TABLE i_e_answer
(
	answer               TEXT NOT NULL,
	i_e_id               TINYINT NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE i_e_answer
ADD PRIMARY KEY (i_e_id,login);



CREATE TABLE i_k_i_answer
(
	answer               TEXT NOT NULL,
	i_k_i_id             TINYINT NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE i_k_i_answer
ADD PRIMARY KEY (i_k_i_id,login);



CREATE TABLE ideal_expert
(
	i_e_id               TINYINT NOT NULL,
	question             TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE ideal_expert
ADD PRIMARY KEY (i_e_id);



CREATE TABLE ideal_knowledge_ingeneer
(
	i_k_i_id             TINYINT NOT NULL,
	question             TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE ideal_knowledge_ingeneer
ADD PRIMARY KEY (i_k_i_id);



CREATE TABLE integ_m_answer
(
	answer               TEXT NOT NULL,
	integration_mean     VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE integ_m_answer
ADD PRIMARY KEY (integration_mean,login);



CREATE TABLE integration_means
(
	integration_mean     VARCHAR(30) NOT NULL
);



ALTER TABLE integration_means
ADD PRIMARY KEY (integration_mean);



CREATE TABLE inter_m_answer
(
	answer               TEXT NOT NULL,
	interface_mean       VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE inter_m_answer
ADD PRIMARY KEY (interface_mean,login);



CREATE TABLE interface_means
(
	interface_mean       VARCHAR(30) NOT NULL
);



ALTER TABLE interface_means
ADD PRIMARY KEY (interface_mean);



CREATE TABLE k_r_answer
(
	answer               TEXT NOT NULL,
	knowledge_representation VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE k_r_answer
ADD PRIMARY KEY (knowledge_representation,login);



CREATE TABLE knowledge_representation
(
	knowledge_representation VARCHAR(30) NOT NULL
);



ALTER TABLE knowledge_representation
ADD PRIMARY KEY (knowledge_representation);



CREATE TABLE m_c_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	company              VARCHAR(30) NOT NULL
);



ALTER TABLE m_c_answer
ADD PRIMARY KEY (login,company);



CREATE TABLE manufacturing_company
(
	company              VARCHAR(30) NOT NULL
);



ALTER TABLE manufacturing_company
ADD PRIMARY KEY (company);



CREATE TABLE o_r_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	o_r_id               TINYINT NOT NULL
);



ALTER TABLE o_r_answer
ADD PRIMARY KEY (login,o_r_id);



CREATE TABLE opportunity_research
(
	o_r_id               TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE opportunity_research
ADD PRIMARY KEY (o_r_id);



CREATE TABLE p_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	platform_name        VARCHAR(30) NOT NULL
);



ALTER TABLE p_answer
ADD PRIMARY KEY (login,platform_name);



CREATE TABLE p_c_answer
(
	answer               TEXT NOT NULL,
	country              VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE p_c_answer
ADD PRIMARY KEY (country,login);



CREATE TABLE p_r_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	p_r_id               TINYINT NOT NULL
);



ALTER TABLE p_r_answer
ADD PRIMARY KEY (login,p_r_id);



CREATE TABLE platform
(
	platform_name        VARCHAR(30) NOT NULL
);



ALTER TABLE platform
ADD PRIMARY KEY (platform_name);



CREATE TABLE producing_country
(
	country              VARCHAR(30) NOT NULL
);



ALTER TABLE producing_country
ADD PRIMARY KEY (country);



CREATE TABLE programming_language
(
	language             VARCHAR(30) NOT NULL
);



ALTER TABLE programming_language
ADD PRIMARY KEY (language);



CREATE TABLE project
(
	project_name         VARCHAR(30) NOT NULL
);



ALTER TABLE project
ADD PRIMARY KEY (project_name);



CREATE TABLE project_group
(
	login                VARCHAR(30) NOT NULL,
	project_name         VARCHAR(30) NOT NULL
);



ALTER TABLE project_group
ADD PRIMARY KEY (login,project_name);



CREATE TABLE propriety_research
(
	p_r_id               TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE propriety_research
ADD PRIMARY KEY (p_r_id);



CREATE TABLE r_l_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	language             VARCHAR(30) NOT NULL
);



ALTER TABLE r_l_answer
ADD PRIMARY KEY (login,language);



CREATE TABLE r_r_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	r_r_id               TINYINT NOT NULL
);



ALTER TABLE r_r_answer
ADD PRIMARY KEY (login,r_r_id);



CREATE TABLE r_v_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	r_v_id               TINYINT NOT NULL
);



ALTER TABLE r_v_answer
ADD PRIMARY KEY (login,r_v_id);



CREATE TABLE references_
(
	r_id                 TINYINT NOT NULL,
	reference            TEXT NOT NULL
);



ALTER TABLE references_
ADD PRIMARY KEY (r_id);



CREATE TABLE relevance_research
(
	r_r_id               TINYINT NOT NULL,
	measure              TEXT NOT NULL,
	weight               TINYINT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE relevance_research
ADD PRIMARY KEY (r_r_id);



CREATE TABLE rigidity_versatility
(
	r_v_id               TINYINT NOT NULL,
	statement            TEXT NOT NULL,
	right_answer         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE rigidity_versatility
ADD PRIMARY KEY (r_v_id);



CREATE TABLE s_l_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	language             VARCHAR(30) NOT NULL
);



ALTER TABLE s_l_answer
ADD PRIMARY KEY (login,language);



CREATE TABLE sol_answer
(
	answer               TEXT NOT NULL,
	solver               VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE sol_answer
ADD PRIMARY KEY (solver,login);



CREATE TABLE solver
(
	solver               VARCHAR(30) NOT NULL
);



ALTER TABLE solver
ADD PRIMARY KEY (solver);



CREATE TABLE sys_answer
(
	answer               TEXT NOT NULL,
	system_name          VARCHAR(30) NOT NULL,
	login                VARCHAR(30) NOT NULL
);



ALTER TABLE sys_answer
ADD PRIMARY KEY (system_name,login);



CREATE TABLE system
(
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system
ADD PRIMARY KEY (system_name);



CREATE TABLE system_integration_means
(
	integration_mean     VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_integration_means
ADD PRIMARY KEY (integration_mean,system_name);



CREATE TABLE system_interface_means
(
	system_name          VARCHAR(30) NOT NULL,
	interface_mean       VARCHAR(30) NOT NULL
);



ALTER TABLE system_interface_means
ADD PRIMARY KEY (system_name,interface_mean);



CREATE TABLE system_knowledge_representation
(
	system_name          VARCHAR(30) NOT NULL,
	knowledge_representation VARCHAR(30) NOT NULL
);



ALTER TABLE system_knowledge_representation
ADD PRIMARY KEY (system_name,knowledge_representation);



CREATE TABLE system_manufacturing_company
(
	company              VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_manufacturing_company
ADD PRIMARY KEY (company,system_name);



CREATE TABLE system_platform
(
	platform_name        VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_platform
ADD PRIMARY KEY (platform_name,system_name);



CREATE TABLE system_producing_country
(
	country              VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_producing_country
ADD PRIMARY KEY (country,system_name);



CREATE TABLE system_realization_language
(
	language             VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_realization_language
ADD PRIMARY KEY (language,system_name);



CREATE TABLE system_solver
(
	system_name          VARCHAR(30) NOT NULL,
	solver               VARCHAR(30) NOT NULL
);



ALTER TABLE system_solver
ADD PRIMARY KEY (system_name,solver);



CREATE TABLE system_supported_language
(
	language             VARCHAR(30) NOT NULL,
	system_name          VARCHAR(30) NOT NULL
);



ALTER TABLE system_supported_language
ADD PRIMARY KEY (language,system_name);



CREATE TABLE t_t_answer
(
	answer               TEXT NOT NULL,
	login                VARCHAR(30) NOT NULL,
	t_t_id               TINYINT NOT NULL
);



ALTER TABLE t_t_answer
ADD PRIMARY KEY (login,t_t_id);



CREATE TABLE temperament_type
(
	t_t_id               TINYINT NOT NULL,
	question             TEXT NOT NULL,
	sincerity            TEXT NOT NULL,
	instability          TEXT NOT NULL,
	extraversion         TEXT NOT NULL,
	a_v_id               TINYINT NOT NULL
);



ALTER TABLE temperament_type
ADD PRIMARY KEY (t_t_id);



CREATE TABLE user
(
	login                VARCHAR(30) NOT NULL,
	password             TEXT NOT NULL,
	name                 TEXT NOT NULL,
	gender               TEXT NOT NULL,
	age                  tinyint NULL,
	group_name           VARCHAR(30) NOT NULL
);



ALTER TABLE user
ADD PRIMARY KEY (login);



CREATE TABLE user_group
(
	group_name           VARCHAR(30) NOT NULL
);



ALTER TABLE user_group
ADD PRIMARY KEY (group_name);



ALTER TABLE c_s_answer
ADD FOREIGN KEY R_4 (login) REFERENCES user (login);



ALTER TABLE c_s_answer
ADD FOREIGN KEY R_6 (c_s_id) REFERENCES creator_speculator (c_s_id);



ALTER TABLE creator_speculator
ADD FOREIGN KEY R_3 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE f_f_answer
ADD FOREIGN KEY R_15 (f_f_id) REFERENCES fielddependence_fieldindependence (f_f_id);



ALTER TABLE f_f_answer
ADD FOREIGN KEY R_16 (login) REFERENCES user (login);



ALTER TABLE fielddependence_fieldindependence
ADD FOREIGN KEY R_9 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE i_e_answer
ADD FOREIGN KEY R_28 (i_e_id) REFERENCES ideal_expert (i_e_id);



ALTER TABLE i_e_answer
ADD FOREIGN KEY R_29 (login) REFERENCES user (login);



ALTER TABLE i_k_i_answer
ADD FOREIGN KEY R_27 (i_k_i_id) REFERENCES ideal_knowledge_ingeneer (i_k_i_id);



ALTER TABLE i_k_i_answer
ADD FOREIGN KEY R_30 (login) REFERENCES user (login);



ALTER TABLE ideal_expert
ADD FOREIGN KEY R_8 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE ideal_knowledge_ingeneer
ADD FOREIGN KEY R_7 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE integ_m_answer
ADD FOREIGN KEY R_64 (integration_mean) REFERENCES integration_means (integration_mean);



ALTER TABLE integ_m_answer
ADD FOREIGN KEY R_65 (login) REFERENCES user (login);



ALTER TABLE inter_m_answer
ADD FOREIGN KEY R_66 (interface_mean) REFERENCES interface_means (interface_mean);



ALTER TABLE inter_m_answer
ADD FOREIGN KEY R_67 (login) REFERENCES user (login);



ALTER TABLE k_r_answer
ADD FOREIGN KEY R_68 (knowledge_representation) REFERENCES knowledge_representation (knowledge_representation);



ALTER TABLE k_r_answer
ADD FOREIGN KEY R_69 (login) REFERENCES user (login);



ALTER TABLE m_c_answer
ADD FOREIGN KEY R_56 (login) REFERENCES user (login);



ALTER TABLE m_c_answer
ADD FOREIGN KEY R_57 (company) REFERENCES manufacturing_company (company);



ALTER TABLE o_r_answer
ADD FOREIGN KEY R_21 (login) REFERENCES user (login);



ALTER TABLE o_r_answer
ADD FOREIGN KEY R_26 (o_r_id) REFERENCES opportunity_research (o_r_id);



ALTER TABLE opportunity_research
ADD FOREIGN KEY R_10 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE p_answer
ADD FOREIGN KEY R_58 (login) REFERENCES user (login);



ALTER TABLE p_answer
ADD FOREIGN KEY R_59 (platform_name) REFERENCES platform (platform_name);



ALTER TABLE p_c_answer
ADD FOREIGN KEY R_54 (country) REFERENCES producing_country (country);



ALTER TABLE p_c_answer
ADD FOREIGN KEY R_55 (login) REFERENCES user (login);



ALTER TABLE p_r_answer
ADD FOREIGN KEY R_22 (login) REFERENCES user (login);



ALTER TABLE p_r_answer
ADD FOREIGN KEY R_25 (p_r_id) REFERENCES propriety_research (p_r_id);



ALTER TABLE project_group
ADD FOREIGN KEY R_74 (login) REFERENCES user (login);



ALTER TABLE project_group
ADD FOREIGN KEY R_73 (project_name) REFERENCES project (project_name);



ALTER TABLE propriety_research
ADD FOREIGN KEY R_12 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE r_l_answer
ADD FOREIGN KEY R_60 (login) REFERENCES user (login);



ALTER TABLE r_l_answer
ADD FOREIGN KEY R_61 (language) REFERENCES programming_language (language);



ALTER TABLE r_r_answer
ADD FOREIGN KEY R_23 (login) REFERENCES user (login);



ALTER TABLE r_r_answer
ADD FOREIGN KEY R_24 (r_r_id) REFERENCES relevance_research (r_r_id);



ALTER TABLE r_v_answer
ADD FOREIGN KEY R_17 (login) REFERENCES user (login);



ALTER TABLE r_v_answer
ADD FOREIGN KEY R_19 (r_v_id) REFERENCES rigidity_versatility (r_v_id);



ALTER TABLE relevance_research
ADD FOREIGN KEY R_11 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE rigidity_versatility
ADD FOREIGN KEY R_14 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE s_l_answer
ADD FOREIGN KEY R_62 (login) REFERENCES user (login);



ALTER TABLE s_l_answer
ADD FOREIGN KEY R_63 (language) REFERENCES programming_language (language);



ALTER TABLE sol_answer
ADD FOREIGN KEY R_70 (solver) REFERENCES solver (solver);



ALTER TABLE sol_answer
ADD FOREIGN KEY R_71 (login) REFERENCES user (login);



ALTER TABLE sys_answer
ADD FOREIGN KEY R_52 (system_name) REFERENCES system (system_name);



ALTER TABLE sys_answer
ADD FOREIGN KEY R_53 (login) REFERENCES user (login);



ALTER TABLE system_integration_means
ADD FOREIGN KEY R_37 (integration_mean) REFERENCES integration_means (integration_mean);



ALTER TABLE system_integration_means
ADD FOREIGN KEY R_38 (system_name) REFERENCES system (system_name);



ALTER TABLE system_interface_means
ADD FOREIGN KEY R_39 (system_name) REFERENCES system (system_name);



ALTER TABLE system_interface_means
ADD FOREIGN KEY R_40 (interface_mean) REFERENCES interface_means (interface_mean);



ALTER TABLE system_knowledge_representation
ADD FOREIGN KEY R_32 (system_name) REFERENCES system (system_name);



ALTER TABLE system_knowledge_representation
ADD FOREIGN KEY R_33 (knowledge_representation) REFERENCES knowledge_representation (knowledge_representation);



ALTER TABLE system_manufacturing_company
ADD FOREIGN KEY R_41 (company) REFERENCES manufacturing_company (company);



ALTER TABLE system_manufacturing_company
ADD FOREIGN KEY R_42 (system_name) REFERENCES system (system_name);



ALTER TABLE system_platform
ADD FOREIGN KEY R_43 (platform_name) REFERENCES platform (platform_name);



ALTER TABLE system_platform
ADD FOREIGN KEY R_45 (system_name) REFERENCES system (system_name);



ALTER TABLE system_producing_country
ADD FOREIGN KEY R_46 (country) REFERENCES producing_country (country);



ALTER TABLE system_producing_country
ADD FOREIGN KEY R_47 (system_name) REFERENCES system (system_name);



ALTER TABLE system_realization_language
ADD FOREIGN KEY R_48 (language) REFERENCES programming_language (language);



ALTER TABLE system_realization_language
ADD FOREIGN KEY R_49 (system_name) REFERENCES system (system_name);



ALTER TABLE system_solver
ADD FOREIGN KEY R_34 (system_name) REFERENCES system (system_name);



ALTER TABLE system_solver
ADD FOREIGN KEY R_35 (solver) REFERENCES solver (solver);



ALTER TABLE system_supported_language
ADD FOREIGN KEY R_50 (language) REFERENCES programming_language (language);



ALTER TABLE system_supported_language
ADD FOREIGN KEY R_51 (system_name) REFERENCES system (system_name);



ALTER TABLE t_t_answer
ADD FOREIGN KEY R_18 (login) REFERENCES user (login);



ALTER TABLE t_t_answer
ADD FOREIGN KEY R_20 (t_t_id) REFERENCES temperament_type (t_t_id);



ALTER TABLE temperament_type
ADD FOREIGN KEY R_13 (a_v_id) REFERENCES answer_variant_list (a_v_id);



ALTER TABLE user
ADD FOREIGN KEY R_72 (group_name) REFERENCES user_group (group_name);


