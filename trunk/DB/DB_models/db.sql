    
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
    
    
    
    CREATE TABLE integration_means
    (
    	id                   TINYINT NOT NULL,
    	integration_mean     TEXT NOT NULL
    );
    
    
    
    ALTER TABLE integration_means
    ADD PRIMARY KEY (id);
    
    
    
    CREATE TABLE interface_means
    (
    	id                   TINYINT NOT NULL,

    	interface_mean       TEXT NOT NULL
    );
    
    
    
    ALTER TABLE interface_means
    ADD PRIMARY KEY (id);
    
    
    
    CREATE TABLE k_r_result
    (
    	u_id                 TINYINT NOT NULL,
    	id                   TINYINT NOT NULL
    );
    
    
    
    ALTER TABLE k_r_result
    ADD PRIMARY KEY (u_id,id);
    
    
    
    CREATE TABLE knowledge_representation
    (
    	id                   TINYINT NOT NULL,
    	knowledge_representation TEXT NOT NULL
    );
    
    
    
    ALTER TABLE knowledge_representation
    ADD PRIMARY KEY (id);
    
    
    
    CREATE TABLE manufacturing_company
    (
    	id                   TINYINT NOT NULL,
    	company              TEXT NOT NULL
    );
    
    
    
    ALTER TABLE manufacturing_company
    ADD PRIMARY KEY (id);
    
    
    
    CREATE TABLE opportunity_research
    (
    	id                   TINYINT NOT NULL,
    	measure              TEXT NOT NULL,
    	weight               TINYINT NOT NULL,
    	a_v_id               TINYINT NOT NULL
    );
    
    
    
    ALTER TABLE opportunity_research
    ADD PRIMARY KEY (id);
    
    
    
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
    
    
    
    CREATE TABLE s_result
    (
    	id                   TINYINT NOT NULL,
    	u_id                 TINYINT NOT NULL
    );
    
    
    
    ALTER TABLE s_result
    ADD PRIMARY KEY (id,u_id);
    
    
    
    CREATE TABLE solver
    (
    	id                   TINYINT NOT NULL,
    	solver               TEXT NOT NULL
    );
    
    
    
    ALTER TABLE solver
    ADD PRIMARY KEY (id);
    
    
    
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
    	login                TEXT NOT NULL,
    	competience_result   bool NULL,
    	r_r_result           bool NULL,
    	p_r_result           bool NULL,
    	o_r_result           bool NULL,
    	research_result      bool NULL,
    	f_f_result           enum('полезависимость','поленезависимость') NOT NULL,
    	c_s_result           ENUM('художник','логическое и художественное мышление','мыслитель') NULL,
    	r_v_result           ENUM('ригидный','черты ригидности и гибкости','гибкий') NULL,
    	t_t_result           ENUM('меланхолик','холерик','сангвиник','флегматик') NULL,
    	prototyping_strategy_result enum('1','2','3') NULL
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
    
    
    
    ALTER TABLE creator_speculator
    ADD FOREIGN KEY R_3 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE equivalents
    ADD FOREIGN KEY R_140 (id) REFERENCES glossary (id);
    
    
    
    ALTER TABLE equivalents
    ADD FOREIGN KEY R_143 (equivalent) REFERENCES glossary (id);
    
    
    
    ALTER TABLE fielddependence_fieldindependence
    ADD FOREIGN KEY R_9 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE ideal_expert
    ADD FOREIGN KEY R_8 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE ideal_knowledge_ingeneer
    ADD FOREIGN KEY R_7 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE k_r_result
    ADD FOREIGN KEY R_144 (u_id) REFERENCES user (u_id);
    
    
    
    ALTER TABLE k_r_result
    ADD FOREIGN KEY R_145 (id) REFERENCES knowledge_representation (id);
    
    
    
    ALTER TABLE opportunity_research
    ADD FOREIGN KEY R_10 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE project_group
    ADD FOREIGN KEY R_74 (u_id) REFERENCES user (u_id);
    
    
    
    ALTER TABLE project_group
    ADD FOREIGN KEY R_73 (pr_id) REFERENCES project (id);
    
    
    
    ALTER TABLE propriety_research
    ADD FOREIGN KEY R_12 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE relevance_research
    ADD FOREIGN KEY R_11 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE rigidity_versatility
    ADD FOREIGN KEY R_14 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE s_result
    ADD FOREIGN KEY R_52 (id) REFERENCES system (id);
    
    
    
    ALTER TABLE s_result
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
    
    
    
    ALTER TABLE temperament_type
    ADD FOREIGN KEY R_13 (a_v_id) REFERENCES answer_variant_list (a_v_id);
    
    
    
    ALTER TABLE user
    ADD FOREIGN KEY R_72 (u_g_id) REFERENCES user_group (id);
    
    
