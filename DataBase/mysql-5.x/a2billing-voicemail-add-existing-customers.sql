TRUNCATE TABLE cc_voicemail_users;
INSERT INTO cc_voicemail_users(`id_cc_card`, `mailbox`, `password`, `context`)
SELECT `id`, `username`, '462434594854315', 'default' FROM cc_card;